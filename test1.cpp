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

int N = 200005;

vector<ll> pre(2 * N);
vector<ll> A(2 * N);

vector<vector<int>> g;
vector<int> sol;
vector<int> vis;

void dfs(ll u) {
  vis[u] = true;

  for (auto x : g[u]) {
    if (vis[x] == 0) {
      dfs(x);
    }
  }
  sol.push_back(u);
}

void solve() {
  ll i, j, m, k, start, n, count;
  ll x, l, r;
  cin >> n >> l >> r;

  g.assign(n + 1, vector<int>());
  vis.assign(n + 1, 0);
  sol.clear();

  ll a, b;
  /*deb2(l, r);*/
  fo(i, 0, n - 1) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);

    /*deb2(a, b);*/
  }
  dfs(r);
  /*deb2(n, l);*/
  for (auto x : sol) {

    cout << x << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
