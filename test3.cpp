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
const int N = 3000007, M = N;
//=======================
//
//

vector<vector<ll>> adj;
vector<ll> par;
int n, i, j, m, k, start, q;

ll dist = 0;

vl ans;

map<string, int> dict;
vector<vector<ll>> dp;
ll recur(ll x, ll y) {

  if (x > y || x < 0 || y >= n) {
    return 0;
  }

  if (dp[x][y] != -1) {
    return dp[x][y];
  }
}

void solve() {
  string s;

  cin >> s;

  n = s.length();
  dp.assign(n, vector<ll>(n, -1));

  cin >> k;

  fo(i, 0, k) {
    string a;
    cin >> a;
    dict[a]++;
  }

  for (i = 0; i < n; i++) {
  }
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
