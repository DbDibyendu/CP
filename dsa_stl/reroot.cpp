
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

using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define pb push_back
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vl> vvl;
//=======================
const int MOD = 1'000'000'007;
const int N = 1e6 + 100, M = N;
//=======================

class Solution {

public:
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl

  static const int N = 100000 + 10;
  int dp[N], dp2[N];

  vector<vector<int>> adj;
  vector<int> ans;
  void dfs(int u, int p, vector<int> &good) {

    if (good[u]) {
      dp[u]++;
    } else {
      dp[u]--;
    }
    for (auto a : adj[u]) {
      if (a == p)
        continue;

      dfs(a, u, good); // calc dp[a]

      if (dp[a] > 0) {
        dp[u] += dp[a];
      }
    }
  }

  void dfs2(int u, int p, vector<int> &good) {

    ans[u] = dp[u];

    for (auto a : adj[u]) {
      if (a == p)
        continue;

      int temp = dp[a];

      int schild = dp[a], spar = dp[u]; // preserve
      dp[u] -= max(0, dp[a]);           // remove contrib of a from u
      dp[a] += max(0, dp[u]);           // add contrib of u to a

      dfs2(a, u, good);

      dp[a] = schild, dp[u] = spar;
    }
  }

  vector<int> maxSubgraphScore(int n, vector<vector<int>> &edges,
                               vector<int> &good) {
    // feels like graph dp
    // rerooting dp it seems
    // root the tree at 0, and calc dp
    adj.assign(n + 1, vector<int>());
    for (auto e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }
    memset(dp, 0, sizeof(dp));
    dfs(0, -1, good);
    int i;

    ans.assign(n, 0);
    // reroot and calculate ans
    dfs2(0, -1, good);

    return ans;
  }
};
