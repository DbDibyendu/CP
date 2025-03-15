
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
ll possible = 1;
vector<vector<ll>> adj;

// Bipartite Graph, color 1 and 2.
// And if adjacent same color, assign possible =0;
//
void dfs(int x, int col) {
  int i;
  vis[x] = col;
  for (auto &a : adj[x]) {
    if (vis[a] == col) {
      possible = 0;
    }
    if (vis[a] == 0) {
      dfs(a, 3 - col);
    }
  }
}

void solve() {

  ll i, j, k, start, count;

  ll l, r;
  cin >> n >> m;
  adj.assign(n + 1, vector<ll>());

  possible = 1;
  vis.assign(n + 1, 0);
  ll a, b;
  fo(i, 0, m) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  fo(i, 1, n + 1) {
    if (vis[i] == 0) {
      dfs(i, 1);
    }
  }
  if (possible == 0) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  fo(i, 1, n + 1) { cout << vis[i] << " "; }
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
