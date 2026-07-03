#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <tuple>
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

    int registerHandler(string pattern) {
        if (pattern.empty()) return 0;
        if (pattern.back() != '/') {
            pattern += '/';
        }

        Node *curr = root;
        string currWord = "";
        
        for (auto ch : pattern) {
            if (ch == '/') {
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
                currWord = "";
            } else {
                currWord += ch;
            }
        }
        
        curr->handlerPattern = pattern.substr(0, pattern.length() - 1); 
        return 1;
    }

    pair<string, vector<string>> getHandler(string path) {
        if (path.empty()) return {"null", {}};
        if (path.back() != '/') {
            path += '/';
        }

        Node *curr = root;
        string finalAns = "";
        vector<string> params;
        string currWord = "";

        for (auto ch : path) {
            if (ch == '/') {
                if (currWord.empty()) continue;

                auto& childMap = curr->child;
                if (childMap.find(currWord) != childMap.end()) {
                    curr = curr->child[currWord];
                } else if (curr->specialChar != "") {
                    params.push_back(currWord);
                    curr = curr->child["#"];
                } else {
                    return {"null", {}};
                }
                currWord = "";
            } else {
                currWord += ch;
            }
        }

        if (curr->handlerPattern != "") {
            return {curr->handlerPattern, params};
        }
        return {"null", {}};
    }

    pair<string, vector<string>> getHandlerV2(string path) {
        if (path.empty()) return {"null", {}};
        if (path.back() != '/') {
            path += '/';
        }

        Node *curr = root;
        queue<tuple<Node*, vector<string>>> q;
        vector<string> arr;
        
        q.push({curr, arr});
        string currWord = "";

        for (auto ch : path) {
            if (ch == '/') {
                if (currWord.empty()) continue;

                int t = q.size();
                if (t == 0) return {"null", {}};

                for (int i = 0; i < t; i++) {
                    auto [currNode, currParams] = q.front();
                    q.pop();

                    auto& childMap = currNode->child;

                    if (childMap.find(currWord) != childMap.end()) {
                        vector<string> tparams = currParams;
                        q.push({currNode->child[currWord], tparams});
                    }

                    if (currNode->specialChar != "") {
                        vector<string> tparams = currParams;
                        tparams.push_back(currWord); 
                        q.push({currNode->child["#"], tparams});
                    }

                    if (currNode->star == true) {
                        vector<string> tparams = currParams;
                        q.push({currNode, tparams}); 
                        q.push({currNode->child["*"], tparams});
                    }
                }
                currWord = "";
            } else {
                currWord += ch;
            }
        }

        
        while (!q.empty()) {
            auto [finalNode, finalParams] = q.front();
            q.pop();

            if (finalNode->handlerPattern != "") {
                return {finalNode->handlerPattern, finalParams};
            }
        }

        return {"null", {}};
    }
};
