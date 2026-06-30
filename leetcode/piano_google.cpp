
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

const int N = 1e6 + 100, M = N;
//=======================

long long fact[N];

long long binpow(long long val, long long deg, long long mod) {
  if (!deg)
    return 1 % mod;
  if (deg & 1)
    return binpow(val, deg - 1, mod) * val % mod;
  long long res = binpow(val, deg >> 1, mod);
  return (res * res) % mod;
}

void initfact() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i);
    fact[i] %= MOD;
  }
}

long long C(ll n, ll i) {
  long long res = fact[n];
  long long div = fact[n - i] * fact[i];
  div %= MOD;
  div = binpow(div, MOD - 2, MOD);
  return (res * div) % MOD;
}

vector<pair<int,int>> getSegments(vector<int>& notes) {
    vector<pair<int,int>> segments;

    int n = notes.size();
    int start = 0;

    int mn = notes[0], mx = notes[0];

    for (int i = 1; i < n; i++) {
        mn = min(mn, notes[i]);
        mx = max(mx, notes[i]);

        if (mx - mn > 4) {
            segments.push_back({start, i - 1});

            // reset
            start = i;
            mn = mx = notes[i];
        }
    }

    // last segment
    segments.push_back({start, n - 1});

    return segments;
}


void solve() {
  ll temp = 0, flag = 1;
  int n;
  int i,j;
  cin>>n;
  vector<int> nums(n);
  for(i=0;i<n;i++) cin>>nums[i];


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
