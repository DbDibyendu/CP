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
const int MOD = 1000000007;
const int N = 1000007, M = N;
//=======================

vl ans;
vl visited;
vector<vector<int>> adj;

void bfs(int x) {
  queue<int> q;

  q.push(x);
  visited[x] = 1;
  while (!q.empty()) {
    int k = q.front();
    q.pop();
    for (auto a : adj[k]) {

      if (visited[a] == false) {
        q.push(a);
        visited[a] = 1;
      }
    }
  }
}

void solve() {
  ll i, j, m, k, start, n, count;
  cin >> n >> m;

  ll x, y;
  adj.assign(n + 1, vector<int>());
  visited.assign(n + 1, 0);
  fo(i, 0, m) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  for (i = 1; i <= n; i++) {

    if (visited[i] == false) {
      bfs(i);
      ans.push_back(i);
    }
  }
  cout << ans.size() - 1 << endl;
  for (i = 1; i < ans.size(); i++) {
    cout << ans[i] << " " << ans[i - 1] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  /*cin >> t;*/
  while (t--) {
    solve();
  }
  return 0;
}
