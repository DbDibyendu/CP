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
//=======================
const int MOD = 1000000007;
const int N = 5005, M = N;
//=======================

ll dp[M][M];
ll A[N];

ll recur(ll n, ll i, ll j) {
  /*deb2(i, j);*/
  /*deb(dp[i][j]);*/
  if (dp[i][j] != -MOD) {
    return dp[i][j];
  }
  if (i == j) {
    /*deb(A[j]);*/
    return dp[i][j] = A[j];
  }
  if (i > j || j < 0 || i > n - 1) {
    return dp[i][j] = MOD;
  }

  dp[i][j] = max(A[i] - recur(n, i + 1, j), A[j] - recur(n, i, j - 1));
  /*deb2(i, dp[i][j]);*/
  return dp[i][j];
}
void solve() {

  ll i, j, m, k, start, n, count;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= n; j++) {
      dp[i][j] = -MOD;
    }
  }

  recur(n, 0, n - 1);
  ll temp = 0;
  fo(i, 0, n) { temp += A[i]; }

  cout << (dp[0][n - 1] + temp) / 2 << endl;
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
