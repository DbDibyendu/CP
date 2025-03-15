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
vl visited(N, 0);
vl dist(N, 0);
vector<vector<pll>> adj;

// Find sorted path in Weighted Path.
// dijkstra (SSSP)
// Time Complexity (V+E)Log(V);
void dijkstra(int x) {
  priority_queue<pll> q;
  q.push({0, x});

  int i;
  for (i = 0; i < N; i++) {
    dist[i] = 1e18;
  }

  dist[x] = 0;
  while (!q.empty()) {
    pll k = q.top();
    q.pop();
    if (visited[k.second])
      continue;
    visited[k.second] = 1;
    for (auto a : adj[k.second]) {
      ll weigh = a.first;
      if (dist[a.second] > dist[k.second] + weigh) {
        dist[a.second] = dist[k.second] + weigh;
        q.push({-dist[a.second], a.second});
      }
    }
  }
}

void solve() {
  ll i, j, m, k, start, n, count;
  cin >> n >> m;

  ll x, y, z;
  adj.assign(n + 1, vector<pll>());
  visited.assign(n + 1, 0);
  fo(i, 0, m) {
    cin >> x >> y >> z;
    adj[x].push_back({y, z});
    adj[y].push_back({x, z});
  }

  dijkstra(1);
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
