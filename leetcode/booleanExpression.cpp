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
  int uniq_id;
};


class ExpressionTree {
// FIX: Added public access specifier so methods can be invoked by external runners
public:

  unordered_map<int, bool> dp;
  unordered_map<TreeNode*, TreeNode*> pars; 
  vector<TreeNode*> leafs;
  TreeNode *root;

  // assuming tree is correct expression tree
  bool calculate(TreeNode *root, TreeNode *parent){
    if (root == nullptr) return false; // Safety check
    bool ans = false;

    root->par = parent;
    pars[root] = parent; // FIX: Must populate the pars map here so BubbleUp knows how to climb up

    if(root->GetNodeType() == AND){
      ans = calculate(root->GetLeft(), root) & calculate(root->GetRight(), root);
    }else if(root->GetNodeType() == OR){
      ans = calculate(root->GetLeft(), root) | calculate(root->GetRight(), root); // FIX: Changed from & to |
    }else if(root->GetNodeType() == XOR){
      ans = calculate(root->GetLeft(), root) ^ calculate(root->GetRight(), root); // FIX: Changed from & to ^
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


  void BubbleUp(TreeNode *curr){ // FIX: Changed return type to void since it doesn't return an explicit value
    if (curr == nullptr) return; // FIX: Added base case guard to stop recursion when reaching past the root node
    
    // FIX: Added defensive checks because NOT nodes have a nullptr child, which would cause ->uniq_id to crash
    int leftNodeAns = (curr->GetLeft() != nullptr) ? dp[curr->GetLeft()->uniq_id] : 0;
    int rightNodeAns = (curr->GetRight() != nullptr) ? dp[curr->GetRight()->uniq_id] : 0;

    bool ans = false;
    switch (curr->GetNodeType()) {
      case AND:
        ans = leftNodeAns & rightNodeAns;
        break; // FIX: Added missing break statement to prevent unintentional fall-through
      case OR:
        ans = leftNodeAns | rightNodeAns;
        break; // FIX: Added missing break statement
      case XOR:
        ans = leftNodeAns ^ rightNodeAns;
        break; // FIX: Added missing break statement
      case NOT:
        if(curr->GetLeft() == nullptr){
          ans = !rightNodeAns; // FIX: Added missing negation (!) for NOT logic
        }else{
          ans = !leftNodeAns;  // FIX: Added missing negation (!) for NOT logic
        }
        break; // FIX: Added missing break statement
    }

    dp[curr->uniq_id] = ans;
    BubbleUp(pars[curr]);
  }

  vector<bool> resultsAfterFlip(){
    vector<bool> finalAns;

    for(auto l: leafs){
      bool original_val = dp[l->uniq_id]; // FIX: Track the original boolean value
      bool flipped_val = !original_val;
      
      dp[l->uniq_id] = flipped_val;
      BubbleUp(pars[l]);
      
      finalAns.push_back(dp[root->uniq_id]);

      // FIX: The problem explicitly states that each leaf is flipped "independently from the rest".
      // If we leave it modified, the mutations compound. We must revert the state before testing the next leaf.
      dp[l->uniq_id] = original_val;
      BubbleUp(pars[l]); 
    }

    return finalAns;
  } 

};
