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
vl visited;
vl dist(N, 0);
vector<vector<pll>> adj;

// Find shortest path in 0/1 graph
// push front and back concept
void bfs_01(int x) {
  deque<int> q;
  q.push_back(x);

  int i;
  for (i = 0; i < N; i++) {
    dist[i] = MOD;
  }

  dist[x] = 0;
  while (!q.empty()) {
    int k = q.front();
    q.pop_front();

    for (auto a : adj[k]) {
      if (dist[a.first] > dist[k] + a.second) {
        dist[a.first] = dist[k] + a.second;

        if (a.second) {
          q.push_back(a.first);
        } else {
          q.push_front(a.first);
        }
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

  bfs_01(1);
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
