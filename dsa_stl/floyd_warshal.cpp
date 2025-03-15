/*#include <bits/stdc++.h>*/
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

// Floyd Warshal algo (APSP)
// all pair shortest path
// Time complexity: O(V. E) = O(V^3)
void solve() {
  ll n, i, j, m, k, start, count, q;
  cin >> n >> m >> q;

  ll a, b, c;

  ll adj[n + 1][n + 1];
  ll dist[n + 1][n + 1];
  fo(i, 0, n + 1) {
    fo(j, 0, n + 1) {
      dist[i][j] = 1e18;
      if (i == j)
        dist[i][j] = 0;
    }
  }

  fo(i, 0, m) {
    cin >> a >> b >> c;
    if (dist[a][b] != 1e18) {
      if (c < dist[a][b]) {
        dist[a][b] = c;
        dist[b][a] = c;
      }
    } else {
      dist[a][b] = c;
      dist[b][a] = c;
    }
  }

  fo(k, 0, n + 1) {
    fo(i, 1, n + 1) {
      fo(j, 1, n + 1) { dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); }
    }
  }

  fo(i, 0, q) {
    cin >> a >> b;
    ll ans = dist[a][b] == 1e18 ? -1 : dist[a][b];
    cout << ans << endl;
  }
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
