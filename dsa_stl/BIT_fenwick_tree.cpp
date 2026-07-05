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
// 🌳 BINARY INDEXED TREE (FENWICK TREE)

/* ❓ WHAT IS A FENWICK TREE?
 * A Fenwick Tree (or BIT) is an elegant data structure that provides a middle 
 * ground between a raw array and a full Segment Tree. 
 *
 * It allows both element updates and range prefix queries in O(log N) time,
 * using exactly O(N) space—matching a standard array's size perfectly.
 *
 * ⚠️ RULES OF THE ROAD:
 * 1. It MUST be 1-Indexed. Index 0 is reserved as a dummy/neutral root.
 * 2. It tracks sums in cumulative blocks whose lengths are powers of 2.
 */

/* 🗺️ VISUALIZATION: RANGE RESPONSIBILITY MAP
 *
 * Every index 'i' stores the sum of a specific range of elements ending at 'i'.
 * The length of that range is determined by the LARGEST POWER OF 2 that divides 'i'.
 *
 * Index (Dec)  Binary   Lowest Set Bit Block Length   Range Covered
 * -----------------------------------------------------------------
 * [1]        0001         1 (2^0)          1        [1]
 * [2]        0010         2 (2^1)          2        [1 to 2]
 * [3]        0011         1 (2^0)          1        [3]
 * [4]        0100         4 (2^2)          4        [1 to 4]
 * [5]        0101         1 (2^0)          1        [5]
 * [6]        0110         2 (2^1)          2        [5 to 6]
 * [7]        0111         1 (2^0)          1        [7]
 * [8]        1000         8 (2^3)          8        [1 to 8]
 *
 * 🧙‍♂️ THE BITWISE MAGIC TRICK: (idx & -idx)
 *
 * How do we know how big an index's block is? We isolate its lowest set bit.
 * In computer math (Two's Complement), doing a bitwise AND between a number 
 * and its negative equivalent isolates that exact lowest '1'.
 *
 * Example: idx = 6 (Binary: 0110)
 * -6     (Binary: 1010)
 * ---------------------
 * 6 & -6 =        0010  --> (Decimal 2) -> Index 6 holds 2 elements!
 */

/* ↘️ QUERYING: THE BINARY DROP (Moving Down/Left)
 * To get the prefix sum from 1 to 7:
 * Start at 7 (0111) -> Read tree[7] (Length 1: element 7)
 * Subtract (7 & -7) -> 7 - 1 = 6 (0110) -> Read tree[6] (Length 2: elements 5-6)
 * Subtract (6 & -6) -> 6 - 2 = 4 (0100) -> Read tree[4] (Length 4: elements 1-4)
 * Subtract (4 & -4) -> 4 - 4 = 0 (0000) -> STOP.
 * Total Sum = tree[7] + tree[6] + tree[4]  --> Done in 3 jumps!
 */

/* ↗️ UPDATING: THE PARENT CLIMB (Moving Up/Right)
 * If element 3 changes, which ranges contain it and need to be updated?
 * Start at 3 (0011) -> Update tree[3]
 * Add (3 & -3)      -> 3 + 1 = 4 (0100) -> Update tree[4]
 * Add (4 & -4)      -> 4 + 4 = 8 (1000) -> Update tree[8]
 * Keep adding until you exceed the max size constraint.
 */
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
      index += index & -index; // Climb up to parent node, get lowest set bit
    }
  }

  // Returns prefix sum from index 0 to 'index' (inclusive, 0-based)
  int query(int index) {
    index++; // Convert to 1-based indexing
    int res = 0;
    while (index > 0) {
      res += tree[index];
      index -= index & -index; // Move to down the tree, by deducting the Lowest set bit
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
      cout << bit.query(r) << endl; // Prefix sum query (1 to N);
    }
  }
}

// 📊 FENWICK TREE (BIT) vs. SEGMENT TREE CODESHEET

/* ⚖️ THE CORE TRADE-OFF:
 * Use a Fenwick Tree for speed, low memory, and minimal code when doing sums.
 * Use a Segment Tree when your range queries involve Max/Min/GCD or Range Updates.
 *
 * +------------------------+---------------------------+---------------------------+
 * | FEATURE                | FENWICK TREE (BIT)        | SEGMENT TREE              |
 * +------------------------+---------------------------+---------------------------+
 * | Code Complexity        | Extremely Low (~15 lines) | High (Deep recursion)     |
 * | Memory Footprint       | Exactly N (Perfect fit)   | 4 * N (Heavy allocation)  |
 * | Native Query Type      | Prefix Only (1 to K)      | Absolute Range (L to R)   |
 * | Arbitrary Range Query  | Indirect (via subtraction)| Direct (via tree walking) |
 * | Point Updates          | O(log N)                  | O(log N)                  |
 * | Range Updates          | Complex / Hard            | Easy (Lazy Propagation)   |
 * | Best Used For...       | Range Sums, Counts        | Range Min/Max, GCD, Multi |
 * +------------------------+---------------------------+---------------------------+
 */

/* 🧠 MEMORY HOOK: HOW THEY TALK TO DATA
 *
 * 1. FENWICK TREE: "I only look from the beginning (1 to K). If you want a middle 
 * range [L, R], I will compute prefix(R) and subtract prefix(L-1). If your 
 * operation can't be subtracted (like Max/Min), don't call me."
 *
 * 2. SEGMENT TREE: "I slice the array into standalone structural boxes. If you 
 * want a middle range [L, R], I will hand-pick the exact boxes that fit your 
 * range and glue their answers together. I don't care what the operation is."
 */



