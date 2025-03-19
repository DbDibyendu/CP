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
const int N = INT_MAX, M = N;
//=======================

void merge(vi &A, int l, int r, int mid) {
  int n1 = mid - l + 1;
  int n2 = r - mid;
  vi B = A;
  int i = l, j = mid + 1, k = l; //! Be carefull about the starting point
  while (i < n1 + l && j < n2 + mid + 1) {
    if (B[i] < B[j]) {
      A[k] = B[i];
      i++;
      k++;
    } else {
      A[k] = B[j];
      j++;
      k++;
    }
  }
  while (i < n1 + l) {
    A[k] = B[i];
    i++, k++;
  }
  while (j < n2 + mid + 1) {
    A[k] = B[j];
    k++, j++;
  }
}

void mergesort(vi &A, int l, int r) {
  if (l < r) {
    int mid = (l + r) / 2;
    mergesort(A, l, mid);
    mergesort(A, mid + 1, r);

    merge(A, l, r, mid);
  }
}

void solve() {

  ll i, j, n, m, k;
  ll temp = 0, flag = 1;
  cin >> n;
  vi A(n);
  read(A);
  mergesort(A, 0, n - 1);
  display(A);
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
