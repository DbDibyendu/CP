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
#define display(A)                                                             \
  for (auto &aa : A)                                                           \
    cout << aa << ' ';                                                         \
  cout << endl;
#define displayP(A)                                                            \
  for (auto &aa : A) {                                                         \
    display(aa);                                                               \
  }
#define read(A)                                                                \
  for (auto &aa : A) {                                                         \
    cin >> aa;                                                                 \
  }
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
//=======================
const int MOD = 1'000'000'007;
const int N = 1e5, M = N;
//=======================

int A[N];

//! 2 pointer logic: QuickSort

// Partition function that places the pivot element in its correct position
int partition(int l, int r) {
  int el = A[r]; // Pivot element is the last element
  // Pointer to track the position of smaller elements than the pivot
  int i = l - 1;
  int j;

  // Traverse the array from left to right
  for (j = l; j < r; j++) {
    // If current element is smaller than the pivot
    if (A[j] < el) {
      i++;              // Move the pointer for smaller elements
      swap(A[i], A[j]); // Swap the smaller element with the current element
    }
  }

  // Place the pivot element in its correct position
  swap(A[i + 1], A[r]); // Pivot goes to the position i + 1
  return i + 1;         // Return the pivot's index
}

// QuickSort function that uses the partition function to recursively sort the
// array
void quicksort(int l, int r) {
  if (l < r) {
    // Base condition: Continue if there is more than one element to sort
    // Partition the array and get the pivot index
    int p = partition(l, r);

    // Sort the left part (elements smaller than the pivot)
    quicksort(l, p - 1);

    // Sort the right part (elements greater than the pivot)
    quicksort(p + 1, r);
  }
}

void solve() {

  ll i, j, n, m, k;
  ll temp = 0, flag = 1;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> A[i];
  }
  quicksort(0, n - 1);
  for (i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

//=======================
