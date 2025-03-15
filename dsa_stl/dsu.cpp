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

// DSU or UnionFind
// Finds total number of connected component in O(6);
// Time Complexity: O(1) To find and merge
//
class DSU {
  int n, set_size;
  // rank is size of the graph here, instead of height.
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
    if (x == parent[x]) {
      return x;
    }
    return parent[x] = find(parent[x]);
  }

  void merge(int x, int y) {
    int rootX, rootY;
    rootX = find(x);
    rootY = find(y);

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

void solve() {
  ll n, i, j, m, k, start, count, q;
  cin >> n >> m >> q;

  DSU dsu1 = DSU(10);
  deb(dsu1.find(1));
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
