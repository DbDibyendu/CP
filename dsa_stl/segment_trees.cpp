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
const int N = INT_MAX, M = N;
//=======================
ll n;
ll A[100000], stree[400004];

// ? Segment Trees

/*🌲 What is a Segment Tree?*/
/*A Segment Tree is a binary tree used to efficiently perform range queries and
 * updates on an array.*/
/**/
/*It splits the array into segments (subarrays).*/
/**/
/*Each node represents a segment (e.g. [l, r]) and stores some aggregate info:
 * like sum, min, max, GCD, etc.
 *
 * Visualisation
 *                        [0-7] max=3
 *                       /            \
 *            [0-3] max=3            [4-7] max=2
 *            /        \             /          \
 *       [0-1] 3    [2-3] 2     [4-5] 2     [6-7] 0
 *       /    \     /    \      /    \       /    \
 *     [0] 3 [1] 0 [2] 0 [3] 2 [4] 0 [5] 2 [6] 0 [7] 0
 *
 *   Only 2 leaf writes → 2×log(N) parent updates. O(log N) total.
 */



class SegmentTree {
private:
    int n;
    std::vector<int> tree;

    // Helper function to build the tree recursively
    void build(const std::vector<int>& arr, int node, int start, int end) {
        // Base case: leaf node represents a single element
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        // Recursively build left and right subtrees
        build(arr, leftChild, start, mid);
        build(arr, rightChild, mid + 1, end);

        // Internal node stores the sum of its children
        tree[node] = tree[leftChild] + tree[rightChild];
    }

    // Helper function for point update
    void update(int node, int start, int end, int idx, int val) {
        // Base case: leaf node to be updated
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        // Decide whether to go left or right
        if (idx <= mid) {
            update(leftChild, start, mid, idx, val);
        } else {
            update(rightChild, mid + 1, end, idx, val);
        }

        // Recalculate the current node's value after the child update
        tree[node] = tree[leftChild] + tree[rightChild];
    }

    // Helper function for range query
    int query(int node, int start, int end, int l, int r) {
        // Case 1: Complete overlap - current range is inside query range [l, r]
        if (l <= start && end <= r) {
            return tree[node];
        }

        // Case 2: No overlap - current range is completely outside query range [l, r]
        if (r < start || end < l) {
            return 0; // Return identity element for sum (which is 0)
        }

        // Case 3: Partial overlap - split and check both sides
        int mid = start + (end - start) / 2;
        int leftSum = query(2 * node + 1, start, mid, l, r);
        int rightSum = query(2 * node + 2, mid + 1, end, l, r);

        return leftSum + rightSum;
    }

public:
    // Constructor
    SegmentTree(const std::vector<int>& arr) {
        n = arr.size();
        if (n > 0) {
            // Memory allocation: 4 * n is the safe upper bound for a segment tree size
            tree.resize(4 * n, 0);
            build(arr, 0, 0, n - 1);
        }
    }

    // Public Update Wrapper (0-indexed)
    void update(int idx, int val) {
        if (idx < 0 || idx >= n) return;
        update(0, 0, n - 1, idx, val);
    }

    // Public Query Wrapper (0-indexed, inclusive range [l, r])
    int query(int l, int r) {
        if (l > r || l < 0 || r >= n) return 0;
        return query(0, 0, n - 1, l, r);
    }
};
