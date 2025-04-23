
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

  vector<int> vis, tin, low;
  vector<vector<int>> ans;
  vector<vector<int>> adj;

  /*
   * Time Complexity: O(V + E)
   *  - We visit every node once and traverse each edge once (since it's an
   * undirected graph).
   *
   * Space Complexity: O(V + E)
   *  - Adjacency list takes O(E) space.
   *  - Arrays vis, tin, and low take O(V) space.
   *  - Recursion stack in worst case takes O(V) space.
   */
  // DFS function to find bridges using Tarjan's Algorithm
  void dfs(int node, int parent, int timer) {
    vis[node]++;                   // Mark current node as visited
    low[node] = tin[node] = timer; // Initialize tin and low time

    for (int a : adj[node]) {
      if (a == parent)
        continue; // Skip the edge leading back to parent

      if (vis[a] == 0) {
        // DFS call for unvisited neighbor
        dfs(a, node, timer + 1);

        // Update low-link value after DFS
        low[node] = min(low[node], low[a]);

        // Bridge condition: no back edge from subtree rooted at `a` to `node`
        // or its ancestors
        if (low[a] > tin[node]) {
          ans.push_back({a, node}); // Critical connection found
        }
      } else {
        // Back edge found, update low value
        low[node] = min(low[node], low[a]);
      }
    }
  }

  // Main function to find all critical connections (bridges) in the graph
  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>> &connections) {
    adj.assign(n + 1, vector<int>()); // Create adjacency list

    for (int i = 0; i < connections.size(); i++) {
      adj[connections[i][0]].push_back(connections[i][1]);
      adj[connections[i][1]].push_back(connections[i][0]);
    }

    vis.assign(n + 1, 0); // Visited array
    tin.assign(n + 1, 0); // Time of insertion
    low.assign(n + 1, 0); // Lowest reachable time

    dfs(0, -1, 1); // Start DFS from node 0

    return ans; // Return list of critical connections (bridges)
  }
};
