
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
vector<vector<int>> dp;
// 13 DP approach
// FIX: Passed nums by constant reference to avoid O(N) copy per call
int recur(int i, int prevH, const vector<int>& nums) {
    int n = nums.size();
    if (i == n) {
        return 0;
    }

    if (dp[i][prevH] != -1) {
        return dp[i][prevH];
    }

    int ans = 1e9;

    // Option 1: Paint this plank vertically.
    // The previous horizontal strokes (if any) can logically pass through this.
    ans = min(ans, 1 + recur(i + 1, min(prevH, nums[i]), nums));

    // Option 2: Paint horizontally (only worth it if height <= n)
    if (nums[i] <= n) {
        if (nums[i] > prevH) {
            // Raise the horizontal strokes up to nums[i]
            ans = min(ans, (nums[i] - prevH) + recur(i + 1, nums[i], nums));
        } else {
            // The plank is already fully covered by the previous horizontal strokes
            ans = min(ans, recur(i + 1, nums[i], nums));
        }
    }

    return dp[i][prevH] = ans;
}

int minStroke(const vector<int>& nums) {
    int n = nums.size();
    // 100MB allocation, safe for 256MB limits
    dp.assign(n + 1, vector<int>(n + 1, -1)); 
    return recur(0, 0, nums);
}



map<int,int> mpLR;


// Divide and Conquer approach // O(N^2) time
int solve(int l, int r, int h, const vector<int>& nums) {
    if (l > r) return 0;

    int n = nums.size();
    // Find the minimum height in the current segment
    int min_idx = l;
    // for (int i = l; i <= r; i++) {
    //     if (nums[i] < nums[min_idx]) { // This part can be delegated to Segment trees, to find min_ind between range
    //         min_idx = i;
    //     }
    // }

    min_idx = mpLR[l*n+r]; // O(1)

    // Cost if we use horizontal strokes up to the minimum height
    int horizontal_cost = (nums[min_idx] - h) 
                        + solve(l, min_idx - 1, nums[min_idx], nums) 
                        + solve(min_idx + 1, r, nums[min_idx], nums);

    // Cost if we just paint this entire segment vertically
    int vertical_cost = r - l + 1;

    return min(vertical_cost, horizontal_cost);
}

int minStrokeV2(const vector<int>& nums) {
  // O(N) memory
    // pre caching of L R range

    int i,j;
    int n = nums.size();
    stack<int> st;

    vector<int> nextLesser(n,n);
    vector<int> prevLesser(n,0);

    for(i=0;i<n;i++){
      while(!st.empty() && nums[i] <= nums[st.top()]){
        nextLesser[st.top()] = i;
        st.pop();
      }
      st.push(nums[i]);
    }

    while(!st.empty()) st.pop();

    for(i=n-1;i>=0;i--){
      while(!st.empty() && nums[i] <= nums[st.top()]){
        prevLesser[st.top()] = i;
        st.pop();
      }
      st.push(nums[i]);
    }

    for(i=0;i<n;i++){
      int L = prevLesser[i];
      int R = nextLesser[i];

      int index = L*n+R; 
      mpLR[index] = i; // very nice trick to store min Eligible index for a given L, R
    }


    return solve(0, nums.size() - 1, 0, nums);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) {
  }
  return 0;
}

//=======================
