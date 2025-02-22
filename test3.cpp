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

  ll q;
  cin >> n >> q;

  vl A(n);
  vl Q(q);

  for (i = 0; i < n; i++) {
    cin >> A[i];
  }

  for (i = 0; i < q; i++) {
    cin >> Q[i];
  }

  ll preMSB[n][33];
  vl preXOR(n + 1, 0);

  preXOR[n] = 0;
  preXOR[n - 1] = A[n - 1];
  for (i = n - 2; i >= 0; i--) {
    preXOR[i] = preXOR[i + 1] ^ A[i];
  }

  for (i = 0; i < n; i++) {
    for (k = 0; k <= 32; k++) {
      preMSB[i][k] = -1;
    }
  }

  for (i = 0; i < n; i++) {
    ll t = A[i];
    ll bit = 0;

    while (t) {
      bit++;
      t = t >> 1;
    }
    for (k = 32; k >= 0; k--) {
      if (k < bit) {
        preMSB[i][k] = i;
      } else if (i > 0) {
        preMSB[i][k] = preMSB[i - 1][k];
      }
    }
  }

  for (j = 0; j < q; j++) {

    ll x = Q[j];
    ll idx = n - 1;
    ll resetEl = 0;
    while (idx >= 0 && x > 0) {
      int msb = findMSB(x);
      int nxt = preMSB[idx][msb];
      x = Q[j] ^ preXOR[nxt + 1];
      idx = nxt;
      if (nxt == -1 || A[nxt] > x)
        break;
      /*deb2(nxt, x);*/
      x ^= A[nxt];
      resetEl = A[nxt];
      idx--;
    }

    cout << n - idx - 1 << " ";
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
