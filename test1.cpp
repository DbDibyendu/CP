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
  while (x) {
    x /= 2;
    ans++;
  }
  return ans;
}

void solve() {

  ll i, j, m, k, start, n, count;

  ll q;
  cin >> n >> q;

  vl A(n);
  vl Q(q);

  read(A);
  read(Q);

  ll preMSB[n+1][33];
  vl preXOR(n, 0);

  vl ans(j, 0);

  preXOR[n - 1] = A[n - 1];
  for (i = n - 2; i >= 0; i--) {
    preXOR[i] = preXOR[i + 1] ^ A[i];
  }

  for (j = 0; j <= 32; j++) {
    for (i = 0; i < n; i++) {

      ll k = findMSB(A[i]);
      if (k == j) {
        preMSB[i][j] = i;
      } else if (i == 0) {
        preMSB[i][j] = MOD;
      } else {
        preMSB[i][j] = preMSB[i - 1][j];
      }
    }
  }

  for (j = 0; j < q; j++) {
    ll k = findMSB(Q[j]);

    deb(preMSB[n - 1][k]);
  }

  /*for (i = 0; i < q; i++) {*/
  /*  cout << ans[i] << " ";*/
  /*}*/
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
