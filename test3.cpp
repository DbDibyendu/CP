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
const int N = 1000007, M = N;
//=======================

ll findMSB(ll x) {
  ll ans = 0;
  while (x > 0) {
    x /= 2;
    ans++;
  }
  return ans - 1;
}

void solve() {

  ll i, j, m, k, start, n, count;

  ll l, r;
  cin >> n >> l >> r;

  vl A(n);
  read(A);

  if (l <= n) {
    cout << A[l - 1] << endl;
    return;
  }
  ll sum = A[0];
  for (i = 1; i < n; i++) {
    sum ^= A[i];
  }

  m = m / 2;

  m -= n;
  if (sum == 0) {
    if (m == n + 1) {
      cout << 1 << endl;
      return;
    }
  } else {
  }
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
