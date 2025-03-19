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
const int N = 1000007, M = N;
//=======================
//
//
vector<int> dist;
vector<vector<int>> graph;
vector<int> visited;

void dfs(int x, int l) {
  visited[x] = 1;

  dist[x] = l;
  for (auto a : graph[x]) {
    if (visited[a] == 0) {
      dfs(a, l + 1);
    }
  }
}
void solve() {
  ll n, i, j, m, k, start, q;
  cin >> n;

  graph.assign(1e6, vector<int>());
  visited.assign(n + 1, 0);
  dist.assign(n + 1, 0);

  ll a, b;
  fo(i, 0, n - 1) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  dfs(1, 0);

  int maxE = 0;
  k = 1;
  for (i = 1; i <= n; i++) {
    if (dist[i] > maxE) {
      maxE = dist[i];
      k = i;
    }
  }
  /*deb2(k, maxE);*/
  visited.assign(n + 1, 0);
  dist.assign(n + 1, 0);
  dfs(k, 0);

  maxE = 0;
  for (i = 1; i <= n; i++) {
    /*deb(dist[i]);*/
    if (dist[i] > maxE) {
      maxE = dist[i];
    }
  }

  cout << maxE << endl;
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
