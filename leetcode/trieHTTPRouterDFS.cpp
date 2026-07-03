#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    string specialChar;
    bool star;
    string handlerPattern; 
    unordered_map<string, Node*> child;

    Node() {
        specialChar = "";
        star = false;
        handlerPattern = "";
    }
};

class Router {
    Node *root;

public:
    Router() {
        root = new Node();
    }

    vector<string> parse(string s){
      vector<string> segments;
      string currS = "";
      for(auto ch: s){
        if(ch == '/'){
          if(!currS.empty()) segments.push_back(currS);
          currS = "";
        }else{
          currS += ch;
        }
      }
      if(!currS.empty()) segments.push_back(currS);

      return segments;
    }

    int registerHandler(string pattern) {
        if (pattern.empty()) return 0;

        vector<string> segs = parse(pattern);
        Node *curr = root;
        
        for (auto currWord : segs) {
                if (currWord.empty()) continue;

                if (currWord[0] == '{') {
                    if (curr->specialChar == "") {
                        curr->specialChar = currWord;
                        curr->child["#"] = new Node();
                        curr = curr->child["#"];
                    } else if (curr->specialChar == currWord) {
                        curr = curr->child["#"];
                    } else {
                        return 0; 
                    }
                } else if (currWord == "**") {
                    curr->star = true;
                    if (curr->child.find("*") == curr->child.end()) {
                        curr->child["*"] = new Node();
                    }
                    curr = curr->child["*"];
                } else {
                    auto& childMap = curr->child;
                    if (childMap.find(currWord) == childMap.end()) {
                        childMap[currWord] = new Node();
                    }
                    curr = curr->child[currWord];
                }
        }
        
        curr->handlerPattern = pattern; 
        return 1;
    }

    bool dfs(Node* curr, int index, const vector<string>& segs, string &finalAns, vector<string>& params){
      int end = segs.size();

      if(index == end){
        if(curr->handlerPattern != ""){
          finalAns = curr->handlerPattern;
          return true;
        }

        if(curr->star){
          finalAns = curr->child["*"]->handlerPattern;
          return true;
        }

        return false;
      }

      auto &childMap = curr->child;
      if(childMap.count(segs[index])){
        if(dfs(curr->child[segs[index]], index+1, segs, finalAns, params)){
          return true;
        }
      }

      if(childMap.count("#")){
        params.push_back(segs[index]);
        if(dfs(curr->child["#"], index+1, segs, finalAns, params)){
          return true;
        }
        params.pop_back();
      }

      if(curr->star){
        if(dfs(curr->child["*"], index, segs, finalAns, params)){
          return true;
        }
        
        if(dfs(curr, index+1, segs, finalAns, params)){
          return true;
        }
      }

      return false;
    }

    pair<string, vector<string>> getHandler(string path) {
        if (path.empty()) return {"null", {}};
        vector<string> segs = parse(path);
        vector<string> params;
        string finalAns;
        Node *curr = root;
        
        if(dfs(curr, 0, segs, finalAns, params)){
          return {finalAns, params};
        }

        return {"null", {}};
    }
};
