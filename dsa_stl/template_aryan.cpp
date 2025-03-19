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

#define ll long long int
using namespace std;

ll MOD = 998244353;
const int N = 1000010;

vector<ll> adj[N];
bool visited[N] = {false};
ll siz[N] = {0};
vector<ll> v;

void dfs(ll u) {
  visited[u] = true;
  for (auto x : adj[u]) {
    if (!visited[x]) {
      v.push_back(x);
      dfs(x);
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  // cin>>t;
  while (t--) {
    ll temp = 0, flag = 1;

    // for making the graph
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= m; i++) {
      ll a;
      cin >> a;
      if (a != 0)
        cin >> temp;

      for (ll j = 0; j < a - 1; j++) {
        ll b;
        cin >> b;
        adj[temp].push_back(b);
        adj[b].push_back(temp);
      }
    }
    // for components
    return 0;
  }
}

int fast_pow(int a, int p) {
  int res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = a * 1ll * a % MOD;
      p /= 2;
    } else {
      res = res * 1ll * a % MOD;
      p--;
    }
  }
  return res;
}

int fact(int n) {
  int res = 1;
  for (int i = 1; i <= n; i++) {
    res = res * 1ll * i % MOD;
  }
  return res;
}

int C(int n, int k) {
  if (k > n) {
    return 0;
  } else
    return fact(n) * 1ll * fast_pow(fact(k), MOD - 2) % MOD * 1ll *
           fast_pow(fact(n - k), MOD - 2) % MOD;
}
