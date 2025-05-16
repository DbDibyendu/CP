
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

int n, i, j, m, k, start, q;

ll dist = 0;
// Manachar's Algorithm
// Longest Palindrome in O(n)
//
vector<int> manacher_odd(string s) {
  int n = s.size();
  vector<int> p(n + 2);

  // r and l are left and right boundaries
  int l = 0, r = 1;

  for (int i = 1; i <= n; i++) {

    // update the p[i] either from mirror or from right or left boundary
    p[i] = max(0, min(r - i, p[l + (r - i)]));

    // update the values around center
    while (s[i - p[i]] == s[i + p[i]]) {
      p[i]++;
    }
    // if boundary goes out
    if (i + p[i] > r) {
      l = i - p[i], r = i + p[i];
    }
  }
  return p;
}

void solve() {
  string s;
  cin >> s;

  int n = s.size();
  if (n == 1) {
    cout << s << endl;
    return;
  }

  // print the string

  string t;
  for (auto c : s) {
    t += string("#") + c;
  }

  t = "$" + t + "^";
  auto p = manacher_odd(t);
  int max_i = 0, max_p = 0;

  for (i = 1; i < p.size() - 1; i++) {
    if (max_p <= p[i]) {
      max_i = i;
      max_p = p[i];
    }
  }

  for (i = max_i - max_p + 1; i < max_i + max_p; i++) {
    if (t[i] != '#' && t[i] != '^') {
      cout << t[i];
    }
  }
  cout << endl;
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
