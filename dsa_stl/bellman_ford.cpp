/*#include<bits/stdc++.h>*/
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
#include <vector>
#endif
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define pi 3.1415926535897932384626
#define display(a)                                                             \
  for (auto &aa : a)                                                           \
    cout << aa << ' ';                                                         \
  cout << endl;
#define displayp(a)                                                            \
  for (auto &aa : a) {                                                         \
    display(aa);                                                               \
  }
#define read(a)                                                                \
  for (auto &aa : a) {                                                         \
    cin >> aa;                                                                 \
  }
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
//=======================
const int mod = 1000000007;
//=======================

int N = 100009;

ll n, m;
vl vis;
vector<vector<pll>> adj(N, vector<pll>());
vl dist(N, 0);
ll neg_cycle = 0;
vl par(N, -1);
// Bellman-Ford Algorithm
// Purpose: Detect negative weight cycles and find shortest paths from a source
// Time Complexity: O(V * E), where V is the number of vertices and E is the
// number of edges

void bellmanFord() {
  ll i, j;
  dist[1] = 0; // Initialize distance to source (vertex 1) as 0

  // Run the algorithm for (V - 1) times
  // If we still find a shorter path in the Vth iteration, a negative cycle
  // exists
  for (i = 1; i <= n; i++) { // O(V) iterations

    // Iterate over all vertices
    for (j = 1; j <= n; j++) {

      // Iterate through all adjacent edges of vertex j
      for (auto a : adj[j]) {
        int v = a.first;   // target vertex of the edge
        int wt = a.second; // weight of the edge

        // Relaxation step: if the path through j to v is shorter, update it
        if (dist[v] > dist[j] + wt) {
          dist[v] = dist[j] + wt;
          par[v] = j; // Update parent to reconstruct path if needed

          // If we're still able to relax edges in the Vth iteration,
          // that means a negative cycle is reachable
          if (i == n - 1) {
            neg_cycle = v; // Store a vertex involved in the negative cycle
            return;        // Exit early upon detecting the cycle
          }
        }
      }
    }
  }
}

void solve() {

  ll i, j, k, start, count;

  ll l, r;
  cin >> n >> m;

  vis.assign(n + 1, 0);
  dist.assign(n + 1, 1e18);

  ll a, b, c;
  fo(i, 0, m) {
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }

  bellmanFord();
  if (neg_cycle == 0) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;

  vl cycle;

  /*fo(i, 0, n) { neg_cycle = par[neg_cycle]; }*/

  ll xx = neg_cycle;
  while (1) {
    cycle.push_back(xx);
    if (cycle.size() > 1 && xx == neg_cycle) {
      break;
    }

    xx = par[xx];
  }
  reverse(cycle.begin(), cycle.end());
  display(cycle);
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
