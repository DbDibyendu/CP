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

class Solution {
public:
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl

  vector<int> vis, disc, low; // disc: discovery time, low: lowest reachable
  vector<vector<int>> ans;    // stores bridges (critical connections)
  vector<vector<int>> adj;    // adjacency list

  /*
   * Time Complexity: O(V + E)
   *  - Each node and each edge is visited once in DFS.
   *
   * Space Complexity: O(V + E)
   *  - Adjacency list: O(E)
   *  - Vectors: vis, disc, low = O(V)
   *  - Recursion stack in worst case: O(V)
   */

  // DFS function to find bridges using Tarjan's Algorithm
  void dfs(int node, int parent, int timer) {
    vis[node] = 1;                  // Mark current node as visited
    disc[node] = low[node] = timer; // Set discovery time and low value

    for (int neighbor : adj[node]) {
      if (neighbor == parent)
        continue; // Skip the edge leading back to the parent node

      if (!vis[neighbor]) {
        // Recurse on the unvisited neighbor
        dfs(neighbor, node, timer + 1);

        // After visiting child, update current node's low value
        low[node] = min(low[node], low[neighbor]);

        // Bridge condition: no back edge from subtree rooted at neighbor
        if (low[neighbor] > disc[node]) {
          ans.push_back({node, neighbor}); // Critical connection (bridge) found
        }

      } else {
        // Back edge encountered, update low[node]
        low[node] = min(low[node], disc[neighbor]);
      }
    }
  }

  // Main function to find all bridges in an undirected graph
  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>> &connections) {
    adj.assign(n, vector<int>()); // Build adjacency list for 0-based graph

    for (const auto &edge : connections) {
      int u = edge[0], v = edge[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vis.assign(n, 0);  // Visited array
    disc.assign(n, 0); // Discovery times
    low.assign(n, 0);  // Low-link values

    dfs(0, -1, 1); // Start DFS from node 0, parent is -1, timer starts at 1

    return ans; // Return all bridges found
  }
};
