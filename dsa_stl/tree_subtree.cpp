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

ll ans = 0;
vl visited;
vl dist(N, 0);
vl par(N, 0);
vl subTreeSize(N, 0);
vector<vector<int>> adj;

// calculate subTree size using this method
// Can be used to solve multiple prblms
//
void dfs(int nn, int pp, int n) {

  par[nn] = pp;

  subTreeSize[nn] = 1;
  for (auto x : adj[nn]) {
    if (x != pp) {
      dfs(x, nn, n);
      subTreeSize[nn] += subTreeSize[x];
    }
  }
}

void solve() {
  ll i, j, m, k, start, n, count;
  cin >> n >> m;

  ll x, y, z;
  adj.assign(n + 1, vector<int>());
  visited.assign(n + 1, 0);
  fo(i, 0, m) {
    cin >> x >> y >> z;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  dfs(1, 0, n);
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
