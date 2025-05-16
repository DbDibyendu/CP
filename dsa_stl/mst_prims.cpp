#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define ll long long
#define pii pair<int, int>

const int N = 1000007;
vector<pii> adj[N]; // adjacency list: adj[node] = {{weight, neighbor}, ...}

/*
Prim's Algorithm:

- Purpose: Find the Minimum Spanning Tree (MST) of a graph.
- Strategy: Start from any node and grow the MST by always picking the
minimum-weight edge connecting a visited node to an unvisited one.

Steps:
1. Initialize all distances to INT_MAX.
2. Start from node 1 (or any arbitrary node).
3. Use a min-heap to pick the edge with the minimum weight.
4. If the node is not already included in the MST, add its cost and mark it
visited.
5. Push all its unvisited neighbors into the heap.
6. Repeat until all nodes are included in the MST.

Time Complexity: O((V + E) * log V)
Space Complexity: O(V + E)
*/

void solve() {
  int n, m;
  cin >> n >> m;

  // Read edges
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u}); // undirected graph
  }

  vector<bool> inMST(n + 1, false);
  priority_queue<pii, vector<pii>, greater<pii>> pq;

  int totalWeight = 0;
  pq.push({0, 1}); // start from node 1 with 0 weight

  while (!pq.empty()) {
    auto [wt, node] = pq.top();
    pq.pop();

    if (inMST[node])
      continue;
    inMST[node] = true;
    totalWeight += wt;

    for (auto [edgeWt, neighbor] : adj[node]) {
      if (!inMST[neighbor]) {
        pq.push({edgeWt, neighbor});
      }
    }
  }

  // Check if all nodes are connected
  for (int i = 1; i <= n; i++) {
    if (!inMST[i]) {
      cout << "NO solution" << endl;
      return;
    }
  }

  cout << totalWeight << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  /* cin >> t; */
  while (t--) {
    solve();
  }
  return 0;
}
