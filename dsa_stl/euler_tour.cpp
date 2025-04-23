/*#include <bits/stdc++.h>*/
#include <climits>
#include <iostream>
#include <unordered_map>
#ifndef _glibcxx_no_assert
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

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN]; // Adjacency list of the tree
vector<int> eulerTour; // Flattened Euler tour of the tree
int first_occur[MAXN]; // First time we enter node
int last_occur[MAXN];  // Last time we exit node

// DFS function to perform Euler Tour
// Time Complexity: O(n)
// Each node is visited once, and each edge is traversed exactly twice (to and
// from). Space Complexity:
// - Call stack: O(h) where h is the height of the tree (O(n) worst case for
// skewed tree)
// - eulerTour vector will have size 2n - 1
// - first_occur and last_occur arrays take O(n) space
void dfs(int node, int parent) {
  first_occur[node] = eulerTour.size(); // Mark first occurrence
  eulerTour.push_back(node);            // Enter node

  for (int neighbor : adj[node]) {
    if (neighbor != parent) {
      dfs(neighbor, node);
      eulerTour.push_back(node); // Re-enter node after visiting child
    }
  }

  last_occur[node] =
      eulerTour.size() - 1; // Last time this node is seen in tour
}

int main() {
  int n;
  cin >> n; // Number of nodes

  // Read edges
  // Time Complexity: O(n)
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // Perform DFS starting from node 1
  dfs(1, -1);

  // Print Euler Tour
  cout << "Euler Tour: ";
  for (int x : eulerTour)
    cout << x << " ";
  cout << "\n";

  // Print first and last occurrences
  for (int i = 1; i <= n; ++i) {
    cout << i << "\t" << first_occur[i] << "\t" << last_occur[i] << "\n";
  }

  return 0;
}
