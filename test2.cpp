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
//
//

vector<vector<ll>> adj;
vector<ll> vis;
vector<ll> par;

vector<ll> fans;
ll n, i, j, m, k, start, q;

ll cycle = 0;

ll dfs(ll x, map<ll, ll> &rec_s) {
  vis[x] = 1;
  ll ans = 0;

  rec_s[x] = 1;
  for (auto a : adj[x]) {
    if (rec_s[a] == 1) {
      par[a] = x;
      return a;
    }

    if (!vis[a]) {
      ans = dfs(a, rec_s);
      if (ans) {
        par[a] = x;
        return ans;
      }
    }
  }

  rec_s[x] = 0;
  return ans;
}

void solve() {
  cin >> n >> m;
  vis.assign(n + 1, 0);
  par.assign(n + 1, 0);
  adj.assign(n + 1, vector<ll>());

  map<ll, ll> rec_s;
  fo(i, 0, m) {
    ll a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    par[b] = a;
  }

  ll t2 = 0;
  for (i = 1; i <= n; i++) {

    if (vis[i] == 0) {
      t2 = dfs(i, rec_s);
    }
  }
  if (t2 == 0) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  ll t = t2;
  /*deb(t2);*/

  for (i = 0; i <= n; i++) {
    t2 = par[t2];
  }

  t = t2;
  if (par[t2] == t)
    t2 = par[t2];

  while (par[t2] != t) {
    fans.push_back(t2);
    t2 = par[t2];
  }
  fans.push_back(t2);
  fans.push_back(par[t2]);
  cout << fans.size() << endl;
  reverse(fans.begin(), fans.end());
  display(fans);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
