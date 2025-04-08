
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

#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))

#define display(A)                                                             \
  for (auto &aa : A)                                                           \
    cout << aa << ' ';                                                         \
  cout << endl;

#define read(A)                                                                \
  for (auto &aa : A) {                                                         \
    cin >> aa;                                                                 \
  }
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
//=======================
//
const int MOD = 1000000007;
const int N = 1000007, M = N;
//=======================

vl ans;

// declare a trie node
struct Node {
  Node *child[26];
  int prefix;
  vector<string> wend;

  Node() {
    prefix = 0;
    for (int i = 0; i < 26; i++) {
      child[i] = NULL;
    }
  }
};

// Trie logic
// Time Complexity: O(s) where s is the length of the string
class Trie {
private:
  Node *root;

public:
  Trie() { root = new Node(); }
  // insert a string into the trie
  void insert(string s) {
    Node *node = root;
    for (int i = 0; i < s.size(); i++) {
      int x = s[i] - 'a';
      if (node->child[x] == NULL) {
        node->child[x] = new Node();
      }
      node->prefix++;
      node = node->child[x];
    }
    node->wend.push_back(s);
  }

  void erase(string s) {
    Node *node = root;
    for (int i = 0; i < s.size(); i++) {
      int x = s[i] - 'a';
      if (node->child[x] == NULL) {
        return;
      }
      node->prefix--;
      node = node->child[x];
    }
  }
};

void solve() {
  ll i, j, m, k, start, n, count;
  cin >> n >> m;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  /*cin >> t;*/
  while (t--) {
    solve();
  }
  return 0;
}
