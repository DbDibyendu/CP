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
// indegree means number of parents of a node
vl indegree(N, 0);

// Kahns algo
//
void kahn(int x) {
  queue<int> q;
  q.push(x);

  while (!q.empty()) {
    int k = q.front();
    q.pop();
    /*deb(k);*/
    ans.push_back(k);

    /*display(adj[k]);*/
    for (auto a : adj[k]) {
      indegree[a]--;
      /*deb(indegree[a]);*/
      if (indegree[a] == 0) {
        /*deb2(a, k);*/
        q.push(a);
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
    indegree[y]++;
  }

  kahn(1);
  display(ans);
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
