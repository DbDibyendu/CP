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
#define gc getchar_unlocked
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define pb push_back
const int N = INT_MAX;
//===========================
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
//=======================
vector<bool> visited;
vector<vector<int>> g;

void edge(int a, int b);
void dfs(ll u);
void bfs(ll u);

void solve() {

  int i, j, n, m, k;
  ll temp = 0, flag = 1;
  cin >> n;

  // ! Important
  visited.assign(n, false);
  g.assign(n, vector<int>());
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

//=======================

// DFS
// Time complexity of DFS = O(V+E)
void edge(int a, int b) {
  //  undirected graph
  g[a].pb(b);
  g[b].pb(a);
}

void dfs(ll u) {
  visited[u] = true;
  for (auto x : g[u]) {
    if (visited[x] == false) {
      dfs(x);
    }
  }
}

// BFS
// Time complexity of BFS = O(V+E)
void bfs(ll u) {
  queue<int> q;

  q.push(u);
  visited[u] = true;
  while (!q.empty()) {
    int f = q.front();
    q.pop();

    for (auto x : g[f]) {
      if (!visited[x]) {
        q.push(x);
        visited[x] = true;
      }
    }
  }
}
