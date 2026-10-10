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

const int N = 1e6 + 100, M = N;
//=======================


class Solution {

public: // FIX: Made the function public so it can be called externally
    int minDistPossibleForMaxDeliveries(vector<int> shops, vector<int> buyers, int dist) {
        int n = shops.size();
        int m = buyers.size();

        // FIX: The maximum possible deliveries is capped by the smaller group, not the larger one.
        int max_del = min(n, m); 
        
        // Sorting both arrays is mandatory for 1D matching to prevent cross-matching overheads.
        sort(shops.begin(), shops.end());
        sort(buyers.begin(), buyers.end());

        // FIX: Space optimized from a massive 3D matrix down to two 2D rows (prev_dp and curr_dp)
        // Rows represent buyers (m+1) and columns represent delivery counts (max_del+1)
        const int INF = 1e9;
        vector<vector<int>> prev_dp(m + 1, vector<int>(max_del + 1, INF));
        
        // Base Case: 0 deliveries always results in 0 distance traveled
        for (int j = 0; j <= m; ++j) {
            prev_dp[j][0] = 0;
        }

        // another dimension
        // Outer loop runs through shops (1-indexed)
        for (int i = 1; i <= n; ++i) {
            vector<vector<int>> curr_dp(m + 1, vector<int>(max_del + 1, INF));
            for (int j = 0; j <= m; ++j) {
                curr_dp[j][0] = 0; // 0 deliveries cost 0 distance
            }

            // Inner loops run through buyers and target delivery counts
            for (int j = 1; j <= m; ++j) {
                for (int k = 1; k <= max_del; ++k) {
                    
                    // Option 1: Skip the current shop 'i' (inherit from previous shop state)
                    int res = prev_dp[j][k];
                    
                    // Option 2: Skip the current buyer 'j' (inherit from current shop, previous buyer)
                    res = min(res, curr_dp[j - 1][k]);
                    
                    // Option 3: Match shop 'i' with buyer 'j' if they are within delivery_range
                    // FIX: Distance is simply the absolute difference. 'dist' is used strictly as a filter.
                    int actual_dist = abs(shops[i - 1] - buyers[j - 1]);
                    if (actual_dist <= dist && prev_dp[j - 1][k - 1] != INF) {
                        res = min(res, prev_dp[j - 1][k - 1] + actual_dist);
                    }
                    
                    curr_dp[j][k] = res;
                }
            }
            // Move the current shop data to become the historical previous layer
            prev_dp = move(curr_dp);
        }

        // FIX: Scan backwards from the absolute highest delivery count 'max_del' down to 0
        // The first valid element we encounter represents the minimum distance for the MAXIMUM possible deliveries.
        for (int k = max_del; k >= 0; k--) {
            if (prev_dp[m][k] != INF) {
                return prev_dp[m][k];
            }
        }

        return 0;
    }

    // follow up 1: 
    // probably we can use shop cloning, insert 5 shops of the same type to the array
    // the Space and Time Complexity remains just the same
};



//=======================
