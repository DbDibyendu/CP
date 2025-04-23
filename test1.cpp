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
#include <deque>
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
typedef vector<pll> vpll;
//=======================
const int MOD = 1'000'000'007;
//=======================

// z algorithm
// O(n)
// Z[i] = the length of the longest substring starting from i which is also a
// prefix of s
//
vector<int> computeZArray(string s) {
  int n = s.length();
  vector<int> Z(n, 0);
  int l = 0, r = 0;

  for (int i = 1; i < n; i++) {
    if (i <= r) {
      Z[i] = min(r - i + 1, Z[i - l]);
    }
    while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
      Z[i]++;
    }
    if (i + Z[i] - 1 > r) {
      l = i, r = i + Z[i] - 1;
    }
  }
  return Z;
}

void solve() {
  ll temp = 0, flag = 1;
  string s;
  cin >> s;
  int n = 9;

  int t = n;
  int cnt = 0;
  while (t) {
    t /= 2;
    cnt++;
  }

  int ans = (1 << cnt) - 1;
  ans++;

  deb(ans);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

//=======================
