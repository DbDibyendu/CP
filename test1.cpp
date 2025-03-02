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

ll recur(ll n, ll a) {
  if (a <= 2 * n) {
    return A[a];
  }

  /*deb2(n, a);*/

  if ((a / 2) % 2 == 1) {
    /*deb(pre[n]);*/
    return pre[n];
  }
  /*deb2(pre[n], recur(n, a / 2));*/
  return pre[n] ^ recur(n, a / 2);
}

void solve() {
  ll i, j, m, k, start, n, count;
  ll x, l, r;
  cin >> n >> l >> r;

  /*deb(l);*/
  for (i = 1; i <= n; i++) {
    cin >> A[i];
    if (i == 1) {
      pre[i] = A[i];
    } else {
      pre[i] = pre[i - 1] ^ A[i];
    }
  }

  if (n % 2 == 0) {
    n++;
    A[n] = pre[n / 2];
    pre[n] = pre[n - 1] ^ A[n];
  }

  for (i = n + 1; i <= 2 * n; i++) {
    A[i] = pre[i / 2];
  }

  for (j = l; j <= r; j++) {
    if (l <= 2 * n) {
      cout << A[l] << endl;
      return;
    }
  }

  /*deb2(n, l);*/
  cout << recur(n, l) << endl;
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
