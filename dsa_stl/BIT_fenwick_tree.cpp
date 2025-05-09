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
// Fenwick Tree (aka Binary Indexed Tree) implementation in C++
// Supports:
// - Point update: add value to a single index
// - Prefix sum query: sum from 0 to index i
//
// Time Complexity:
// - update(i, delta): O(log N)
// - query(i): O(log N)
//
// Space Complexity: O(N)
//
// Class definition
class FenwickTree {
private:
  vector<int> tree;

public:
  // Constructor: initializes BIT for given size
  FenwickTree(int size) : tree(size + 1, 0) {}

  // Add 'delta' to element at index 'i' (0-based)
  void update(int index, int delta) {
    index++; // Convert to 1-based indexing
    while (index < tree.size()) {
      tree[index] += delta;
      index += index & -index; // Move to next responsible node
    }
  }

  // Returns prefix sum from index 0 to 'index' (inclusive, 0-based)
  int query(int index) {
    index++; // Convert to 1-based indexing
    int res = 0;
    while (index > 0) {
      res += tree[index];
      index -= index & -index; // Move to parent node
    }
    return res;
  }
};

// Example driver to demonstrate Fenwick Tree usage
void solve() {
  // Example:
  // n = 5, array = [1, 2, 3, 4, 5]
  // Queries:
  //   sum 2 -> sum of [1,2,3] = 6
  //   add 1 3 -> array[1] += 3 => array becomes [1,5,3,4,5]
  //   sum 2 -> sum of [1,5,3] = 9
  //   sum 4 -> sum of [1,5,3,4,5] = 18

  ll n, q;
  cin >> n >> q;
  FenwickTree bit(n);
  vector<int> arr(n);

  // Input array and build tree
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    bit.update(i, arr[i]); // Build Fenwick Tree with initial values
  }

  // Handle queries
  while (q--) {
    string type;
    cin >> type;

    if (type == "add") {
      int i, x;
      cin >> i >> x;
      bit.update(i, x); // Point update: add x to arr[i]
    } else if (type == "sum") {
      int r;
      cin >> r;
      cout << bit.query(r) << endl; // Prefix sum query
    }
  }
}
