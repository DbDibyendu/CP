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
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define display(A)                                                             \
  for (auto &aa : A)                                                           \
    cout << aa << ' ';                                                         \
  cout << endl;
#define displayP(A)                                                            \
  for (auto &aa : A) {                                                         \
    display(aa);                                                               \
  }
#define read(A)                                                                \
  for (auto &aa : A) {                                                         \
    cin >> aa;                                                                 \
  }
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
//=======================
const int MOD = 1'000'000'007;
//=======================

const int N = 1e6 + 100, M = N;
//=======================


class StableGraph {
    vector<vector<int>> adj;
    // FIX: Changed map value type to double to prevent integer truncation (e.g. 10/3 -> 3.333...)
    unordered_map<int, double> node_val; 
    unordered_set<int> prev_node;
    int graph_size;

public:
    StableGraph(vector<vector<int>> graph, int total_nodes) {
        adj = graph;
        graph_size = total_nodes;
        // FIX: Initialize all nodes to 0.0 default value
        for (int i = 0; i < total_nodes; i++) {
            node_val[i] = 0.0;
        }
    }

    // FIX: Changed k to double to handle floating-point inputs
    void trigger(int node, double k) {
        node_val[node] = k;
        prev_node.clear(); // FIX: Clear any stale active nodes from previous triggers
        prev_node.insert(node);
    }

    bool step() {
        // FIX: If no nodes changed in the last step, the graph is already stable!
        if (prev_node.empty()) return true;

        unordered_set<int> next_nodes;

        // FIX: Replaced `prev_node.end()` dereference (SegFault) and unsafe `erase()` 
        // with a clean range-based for loop over active nodes
        for (int u : prev_node) {
            double total_sum = node_val[u]; // FIX: Changed to double for accurate sums
            int size = adj[u].size() + 1;

            for (auto &v : adj[u]) {
                total_sum += node_val[v];
            }

            double new_val = total_sum / size; // FIX: Double precision division

            // Update center node
            node_val[u] = new_val;

            // Update neighbor nodes
            for (auto &v : adj[u]) {
                // FIX: Only queue neighbor if its value ACTUALLY changed (beyond floating-point epsilon)
                if (abs(node_val[v] - new_val) > 1e-9) {
                    node_val[v] = new_val;
                    next_nodes.insert(v);
                }
            }
        }

        prev_node = next_nodes;

        // worst case
        // TC: O(steps* (V+E)) ~= O(V*(V+E))
        // SC: O(V+E + V) to maintain the adj list
        // FIX: Return true if no new nodes changed (graph has stabilized), else false
        return prev_node.empty();
    }
};
//=======================
