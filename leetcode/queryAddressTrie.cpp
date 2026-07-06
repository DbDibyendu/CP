#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// stree number, stree name, city name, state name;

struct Node{
  unordered_map<string, Node*> child;
};


class AddressManager{

  Node* root;

  AddressManager(){
    root = new Node();
  }
  void initAddress(vector<vector<string>> address){


    int i,j;
    for(i=0;i<address.size();i++){
    Node *curr = root;
      for(j=0;j<4;j++){
        if(curr->child.find(address[i][j]) == curr->child.end()){
          curr->child[address[i][j]] = new Node();
        }
        curr = curr->child[address[i][j]];
      }
        // time : O(N*K) 
        // space : O(N*K)
    }
  }


  bool queryHelper(int i, vector<string> query, Node *curr, vector<string> &ans){

      bool possible = false;
      if(i == 4) return true;
      if(curr == nullptr) return false;

      if(query[i] == ""){
        // try out all nodes
        for(auto a: curr->child){
          if(queryHelper(i+1, query, a.second, ans)){
            ans.push_back(a.first);
            possible = true;
            break;
          }
        }
      }else{
        auto it = curr->child.find(query[i]);
        if(it == curr->child.end() || it->second == nullptr){
          return false; 
        }else{
          curr = it->second;
          if(queryHelper(i+1, query, curr, ans)){
            ans.push_back(query[i]);
            possible = true;
          }
        }
      }

      // best query time
      // TC : O(N) worst, if only 1 of the 4 variable is null then O(N^1/4)
      // SC: O(N*K)
      // Reasoning a*b*c*d = N (uniqueue paths)
      return possible;
  }
  vector<string> queryAddress(vector<string> query){

    Node *curr = root;

    vector<string> ans;

    if(!queryHelper(0, query, curr, ans)) return {};
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
