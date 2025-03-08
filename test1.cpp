#include <bits/stdc++.h>
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
const int N = 1000007, M = N;
//=======================

vector<ll> pre(2 * N);
vector<ll> A(2 * N);

vector<vector<int>> g;
vector<vector<int>> depth;
vector<int> dpVal;
vector<int> vis;
vector<int> dp;

int MOD = 998244353;

void solve() {
  ll i, j, m, k, start, n, count;
  string s;
  cin >> n;
  vl A(n);

  read(A);

  vl mp(n + 1, 0);
  bool flag = 0;
  ll x, y;
  ll Max = 0, Min = 1e9;
  fo(i, 0, n) {
    if (A[i] > Max) {
      x = i;
      Max = A[i];
    }
    if (A[i] < Min) {
      y = i;
      Min = A[i];
    }
  }
  vl B(2, 0);

  if (Max - Min == 1) {

    fo(i, 0, n) { mp[A[i]]++; }
    if (mp[2] == 2) {

      cout << "? " << 1 << " " << 2 << endl;
      cin >> i;
      cout << "? " << 3 << " " << 2 << endl;
      cin >> j;
    } else if (mp[3] == 2) {

      cout << "? " << 1 << " " << 3 << endl;
      cin >> i;
      cout << "? " << 2 << " " << 3 << endl;
      cin >> j;
    } else {

      cout << "? " << 3 << " " << 1 << endl;
      cin >> i;
      cout << "? " << 2 << " " << 1 << endl;
      cin >> j;
    }

    if (i == 0 || j == 0) {
      cout << "! A" << endl;
    } else {
      cout << "! B" << endl;
    }
    return;
  }

  cout << "? " << x + 1 << " " << y + 1 << endl;
  cin >> i;
  cout << "? " << y + 1 << " " << x + 1 << endl;
  cin >> j;

  if (i == j && (i >= Max - Min)) {
    cout << "! B" << endl;
  } else {
    cout << "! A" << endl;
  }
  cout.flush();
  // adding 1 because of root node
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
