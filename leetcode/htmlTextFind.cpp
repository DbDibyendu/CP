#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Given DOM API Interface
class Node {
public:
  std::string GetText() const;
  std::vector<const Node*> GetChildren() const;
  const Node* GetParent() const;
  bool IsText() const;
};

// 🛠️ Pass state by reference to eliminate buggy global variables
void parse(const Node* head, string& flatten_text, unordered_map<int, const Node*>& charToNodeMap) {
  if (head == nullptr) return;

  if (head->IsText()) {
      int startI = flatten_text.length();
      flatten_text += head->GetText();
      int endI = flatten_text.length() - 1;
      
      // 🛠️ Map each character index directly to the immutable Node pointer
      for (int i = startI; i <= endI; i++) {
          charToNodeMap[i] = head;
      }
      return;
  }

  // Traverse children in-order
  for (const Node* child : head->GetChildren()) {
      parse(child, flatten_text, charToNodeMap);
  }
}

vector<const Node*> FindText(const Node* head, const std::string& search) {
  string flatten_text = "";
  unordered_map<int, const Node*> charToNodeMap;

  // Run the in-order flattening pass
  parse(head, flatten_text, charToNodeMap);

  // Perform standard string matching
  size_t it = flatten_text.find(search);
  if (it == string::npos) return {};

  vector<const Node*> ans;
  size_t match_end = it + search.length();

  // 🛠️ Read from our map to translate string indices back to real DOM nodes
  for (size_t i = it; i < match_end; i++) {
      const Node* currentNode = charToNodeMap[i];
      
      if (ans.empty() || ans.back() != currentNode) {
          ans.push_back(currentNode);
      }
  }

  return ans;
}
