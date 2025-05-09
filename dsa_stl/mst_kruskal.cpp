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
const int MOD = 1000000007;
const int N = 1000007, M = N;
//=======================

// DSU or UnionFind
class DSU {
  int n, set_size;
  vi parent, rank;

public:
  DSU(int a) {
    n = set_size = a;
    parent.assign(n + 1, 0);
    rank.assign(n + 1, 1);
    for (int i = 0; i <= n; i++) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (x == parent[x])
      return x;
    return parent[x] = find(parent[x]);
  }

  void merge(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY)
      return;
    if (rank[rootX] >= rank[rootY]) {
      parent[rootY] = rootX;
      rank[rootX] += rank[rootY];
    } else {
      parent[rootX] = rootY;
      rank[rootY] += rank[rootX];
    }
    set_size--;
  }
};

/*
Kruskal's Algorithm:

- Purpose: Find the Minimum Spanning Tree (MST) of a graph.
- Strategy: Greedily pick the smallest available edge that connects two
different components.
- Ensures no cycles are formed while connecting all nodes with minimal total
cost.

Steps:
1. Sort all edges based on weight.
2. Use DSU (Disjoint Set Union) to track connected components.
3. For each edge:
   - If it connects two different components, add it to MST and merge the
components.
   - Otherwise, skip (to avoid cycles).
4. If MST has (n - 1) edges, output its total weight; else, "NO solution" (graph
is disconnected).

Time Complexity:
- Sorting edges: O(m log m)
- DSU operations (find/merge): almost O(1) with path compression
- Processing edges: O(m)
=> Overall: O(m log m)

Space Complexity:
- DSU arrays (parent, rank): O(n)
- Edge list storage: O(m)
=> Overall: O(n + m)
*/

void solve() {
  ll n, m;
  cin >> n >> m;

  DSU dsu1(n);
  vector<pair<int, pair<int, int>>> edges;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({c, {a, b}});
  }

  sort(edges.begin(), edges.end());

  int mst_val = 0, count = 0;
  for (auto x : edges) {
    int n1 = x.second.first;
    int n2 = x.second.second;
    if (dsu1.find(n1) != dsu1.find(n2)) {
      mst_val += x.first;
      dsu1.merge(n1, n2);
      count++;
    }
  }

  if (count != n - 1) {
    cout << "NO solution" << endl;
    return;
  }
  cout << mst_val << endl;
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
