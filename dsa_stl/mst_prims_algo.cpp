#include <climits>
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
const int MOD = 1000000007;
const int N = 1000007, M = N;
//=======================

/*
Prim's Algorithm:

- Purpose: Find the Minimum Spanning Tree (MST) of a graph.
- Strategy: Start from any node, grow the MST by adding the smallest edge
  connecting to an unvisited node.

Steps:
1. Use a priority queue (min-heap) to always pick the smallest available edge.
2. Start from any node (say node 1).
3. Keep visiting new nodes and adding their edges into the heap.
4. Only add edges to unvisited nodes to avoid cycles.
5. Repeat until all nodes are visited.

Time Complexity:
- Pushing/Popping edges: O((m + n) log n)
=> Overall: O(m log n)

Space Complexity:
- Priority queue + visited array + adjacency list: O(m + n)
*/

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n + 1); // {node, weight}

  for (int i = 0; i < m; i++) {
    int u, v, wt;
    cin >> u >> v >> wt;
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  vector<bool> visited(n + 1, false);

  pq.push({0, 1}); // {weight, node}

  int mst_val = 0, count = 0;

  while (!pq.empty()) {
    auto [wt, u] = pq.top();
    pq.pop();

    if (visited[u])
      continue;

    visited[u] = true;
    mst_val += wt;
    count++;

    for (auto [v, w] : adj[u]) {
      if (!visited[v]) {
        pq.push({w, v});
      }
    }
  }

  if (count != n) {
    cout << "NO solution" << endl;
    return;
  }
  cout << mst_val << endl;
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
