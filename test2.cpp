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

int M = 100000009;

vector<ll> pre(2 * N);
vector<ll> A(3 * N);

string s;
bool check(ll x, ll n, ll k) {
  bool flag = 1;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    /*deb2(s[i], A[i]);*/
    /*deb(x);*/
    if (s[i] == 'B' && A[i] > x) {
      ans += flag;
      flag = 0;
    } else if (s[i] == 'R' && A[i] > x) {
      flag = 1;
    }
  }
  /*deb(ans);*/
  return ans <= k;
}

void solve() {
  ll i, j, m, k, start, n, count;
  ll x, l, r;
  cin >> n >> k;
  cin >> s;
  ll maX = 0;
  for (i = 0; i < n; i++) {
    cin >> A[i];
    maX = max(A[i], maX);
  }

  ll ans, mid;

  l = 0, r = maX;
  while (l <= r) {
    mid = (l + r) / 2;
    /*deb(mid);*/
    /*deb2(l, r);*/
    if (check(mid, n, k)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << ans << endl;
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
