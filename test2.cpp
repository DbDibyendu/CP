/*#include<bits/stdc++.h>*/
#include <iostream>
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
const int N = INT_MAX, M = N;
//=======================

int CallMe(int i, vi &dp, vi &arr, string &s, int result, vi &visited) {

  ll ans = 0;

  if (dp[i] != -1) {
    return dp[i];
  }
  if (visited[i] == 2) {
    // to update each node
    dp[i] = result;
    visited[i] += 1;
    CallMe(arr[i], dp, arr, s, result, visited);
    return dp[i];
  }
  if (visited[i] == 3) {
    // to just stop the infinite loop
    return ans;
  }
  if (s[arr[i] - 1] == '0' && visited[i] == 0) {
    ans += 1;
  }

  if (arr[i] != i) {
    visited[i] += 1;
    if (visited[i] == 1) {
      result = CallMe(arr[i], dp, arr, s, result, visited) + ans;
      CallMe(arr[i], dp, arr, s, result, visited);
    }
    return result;
  }
  dp[i] = ans;
  return ans;
}

void solve() {

  ll i, j, n, m, k, start, count;
  ll temp = 0, flag = 1;
  cin >> n;
  vi arr(n + 1), dp(n + 1, -1), visited(n + 1, 0);
  fo(i, 0, n) { cin >> arr[i + 1]; }
  string s;
  cin >> s;
  count = 0;
  fo(i, 0, n) { dp[i + 1] = CallMe(i + 1, dp, arr, s, 0, visited); }

  fo(i, 0, n) { cout << dp[i + 1] << " "; }
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

//=======================
