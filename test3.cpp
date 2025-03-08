/*#include<bits/stdc++.h>*/
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
#include <vector>
#endif
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define pi 3.1415926535897932384626
#define display(a)                                                             \
  for (auto &aa : a)                                                           \
    cout << aa << ' ';                                                         \
  cout << endl;
#define displayp(a)                                                            \
  for (auto &aa : a) {                                                         \
    display(aa);                                                               \
  }
#define read(a)                                                                \
  for (auto &aa : a) {                                                         \
    cin >> aa;                                                                 \
  }
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
//=======================
const int mod = 1000000007;
//=======================

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> visited;

vector<string> graph(1000);
int n, m;

bool check(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m) {
    return 0;
  }
  if (graph[x][y] == '#') {
    return 0;
  }
  return 1;
}
void dfs(int x, int y) {
  visited[x][y] = true;

  int i;
  for (i = 0; i < 4; i++) {
    if (check(x + dx[i], y + dy[i]) && visited[x + dx[i]][y + dy[i]] == false) {
      dfs(x + dx[i], y + dy[i]);
    }
  }
}
void solve() {

  ll i, j, k, start, count;

  ll l, r;
  cin >> n >> m;

  fo(i, 0, n) {
    cin >> graph[i];
    /*deb(graph[i]);*/
  }

  visited.assign(1000, vector<int>(1000, 0));

  ll ans = 0;
  fo(i, 0, n) {
    fo(j, 0, m) {
      if (visited[i][j] == false && graph[i][j] == '.') {
        ans++;
        dfs(i, j);
      }
    }
  }
  cout << ans;
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
