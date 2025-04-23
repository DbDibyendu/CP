
/*#include <bits/stdc++.h>*/
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

const int MAXN = 1e5 + 5; // Max number of nodes
const int LOG = 20;       // ceil(log2(MAXN))

vector<int> adj[MAXN]; // Tree adjacency list
int up[MAXN][LOG];     // up[v][j] = 2^j-th ancestor of v
int depth[MAXN];       // depth of each node

// Preprocessing DFS to build binary lifting table
// leetcode prblm:
// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/
//
void dfs(int v, int parent) {
  up[v][0] = parent; // Immediate parent (2^0-th ancestor)
  for (int i = 1; i < LOG; i++) {
    if (up[v][i - 1] != -1)
      up[v][i] = up[up[v][i - 1]][i - 1]; // DP step
    else
      up[v][i] = -1;
  }

  for (int u : adj[v]) {
    if (u != parent) {
      depth[u] = depth[v] + 1;
      dfs(u, v);
    }
  }
}

// Lifts node u up by k levels in the tree
int lift_node(int u, int k) {
  for (int i = 0; i < LOG; i++) {
    if (k & (1 << i)) {
      u = up[u][i];
      if (u == -1)
        break; // Went past root
    }
  }
  return u;
}

// Finds LCA of nodes u and v
int lca(int u, int v) {
  if (depth[u] < depth[v])
    swap(u, v);

  // Bring u and v to same depth
  u = lift_node(u, depth[u] - depth[v]);

  if (u == v)
    return u; // v is ancestor of u

  // Lift both u and v until their ancestors match
  for (int i = LOG - 1; i >= 0; i--) {
    if (up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }

  return up[u][0]; // Return parent of u or v
}

// Example usage
int main() {
  int n;
  cin >> n;

  // Build the tree (assuming 1-based indexing)
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  memset(up, -1, sizeof(up));
  depth[1] = 0;
  dfs(1, -1); // Root the tree at node 1

  // Query examples
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << "LCA of " << u << " and " << v << " is " << lca(u, v) << "\n";
  }

  return 0;
}
