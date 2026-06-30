
/*#include <bits/stdc++.h>*/
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
#include <deque>
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
//=======================


int solve(int n, vector<int> nums, int K) {
    if (n < 2) return -1;

    vector<int> prefix(n, 0);
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = nums[i] + prefix[i-1];
    }

    vector<int> numsI(n, 0);
    for (int i = 0; i < n; i++) {
        numsI[i] = nums[i] + prefix[i];
    }

    deque<int> dq; // Explicitly stores INDICES
    int max_val = -1e9;

    // 'i' acts as our right endpoint (j)
    for (int i = 1; i < n; i++) {
        int prev = i - 1; // Our new prospective left endpoint candidate

        // 1. Maintain a strictly decreasing monotonic queue based on VALUES
        while (!dq.empty() && numsI[prev] >= numsI[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(prev);

        // 2. Evict indices that breach the maximum size constraint K
        // Subarray length = i - left_idx + 1. If length > K, then left_idx < i - K + 1
        while (!dq.empty() && dq.front() < i - K + 1) {
            dq.pop_front();
        }

        // 3. Extract the optimal value using the index at the front of the deque
        int best_left_idx = dq.front();
        int current_score = numsI[best_left_idx] + nums[i] - prefix[i-1];
        
        max_val = max(max_val, current_score);
    }

    return max_val;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) {
    // solve();
  }
  return 0;
}

//=======================
