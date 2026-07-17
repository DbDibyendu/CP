#include <iostream>
#include <unordered_map>
#ifndef _GLIBCXX_NO_ASSERT
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
#endif

using namespace std;

// main question

enum NodeType {
  AND,
  OR,
  XOR,
  NOT,
  BOOLEAN
};

class TreeNode {
  public:
  NodeType GetNodeType();
  bool GetBooleanValue();
  TreeNode* GetLeft();
  TreeNode* GetRight();
  TreeNode* par;
  bool isCritical;
  int uniq_id;

  TreeNode(){
    isCritical = false;
  }
};


class ExpressionTree {
// FIX: Added public access specifier so methods can be invoked by external runners
public:

  unordered_map<int, bool> dp;
  vector<TreeNode*> leafs;
  TreeNode *root;

  // assuming tree is correct expression tree
  bool calculate(TreeNode *root, TreeNode *parent){
    if (root == nullptr) return false; // Safety check
    bool ans = false;

    root->par = parent;

    if(root->GetNodeType() == AND){
      ans = calculate(root->GetLeft(), root) & calculate(root->GetRight(), root);
    }else if(root->GetNodeType() == OR){
      ans = calculate(root->GetLeft(), root) | calculate(root->GetRight(), root); 
    }else if(root->GetNodeType() == XOR){
      ans = calculate(root->GetLeft(), root) ^ calculate(root->GetRight(), root); 
    }else if(root->GetNodeType() == NOT){
      if(root->GetLeft() != nullptr){
        ans = !calculate(root->GetLeft(), root);
      }else{
        ans = !calculate(root->GetRight(), root);
      }
    }else if(root->GetNodeType() == BOOLEAN){
      leafs.push_back(root);
      ans = root->GetBooleanValue();
    }

    return dp[root->uniq_id] = ans;
  }

  // FIX: Changed default value to true because the root is always critical to its own final evaluation output
  void populateIsCritical(TreeNode *root, bool criticalVal = true){ 

    if (root == nullptr) return; // Safety check

    root->isCritical = criticalVal;

    // FIX: Removed the line `if(root->GetLeft() == nullptr || root->GetRight() == nullptr) return;`
    // This was causing a severe bug for NOT nodes (which have one nullptr child), causing the function to stop early and miss processing their valid child.

    // FIX: Only fetch leftVal and rightVal if the respective children actually exist to prevent a segmentation fault crash
    int leftVal = (root->GetLeft() != nullptr) ? dp[root->GetLeft()->uniq_id] : 0;
    int rightVal = (root->GetRight() != nullptr) ? dp[root->GetRight()->uniq_id] : 0; // FIX: Fixed copy-paste typo where you read GetLeft() instead of GetRight()

    // FIX: Rewrote the boolean logic rules. 
    // 1. A child can only be critical to the root if its parent is already critical (criticalVal == true).
    // 2. For an AND node, the left child is critical ONLY if the right sibling is true. 
    // 3. If a child is critical to its parent, it inherits the parent's criticality status (criticalVal), not its inversion (!criticalVal).
    if(root->GetNodeType() == AND){
      populateIsCritical(root->GetLeft(), criticalVal && (rightVal == 1));
      populateIsCritical(root->GetRight(), criticalVal && (leftVal == 1));
    }else if(root->GetNodeType() == OR){
      populateIsCritical(root->GetLeft(), criticalVal && (rightVal == 0));
      populateIsCritical(root->GetRight(), criticalVal && (leftVal == 0));
    }else if(root->GetNodeType() == XOR){
      // pass parent's criticality
      populateIsCritical(root->GetLeft(), criticalVal);
      populateIsCritical(root->GetRight(), criticalVal);
    }else if(root->GetNodeType() == NOT){
      // Pass the parent's criticality directly down to whichever child exists
      if(root->GetLeft() != nullptr) populateIsCritical(root->GetLeft(), criticalVal);
      else populateIsCritical(root->GetRight(), criticalVal);
    }
  }

  vector<bool> resultsAfterFlip(){

    // FIX: You completely missed calling your preprocessing setup methods! 
    // Without running these first, your maps and values are uninitialized when this function executes.
    calculate(root, nullptr);
    populateIsCritical(root, true);

    vector<bool> ans;
    bool base_root_value = dp[root->uniq_id]; // FIX: Cache the original root value

    for(auto l: leafs){
      // FIX: Changed from `!dp[l->uniq_id]` to `!base_root_value`.
      // The problem asks for the evaluation result of the entire tree (the root).
      // If a leaf is critical, it means flipping it will flip the final ROOT answer. If it is not critical, the root answer remains unchanged.
      bool curr_ans = l->isCritical ? !base_root_value : base_root_value;
      ans.push_back(curr_ans);
    } 

    return ans;
  }
};
