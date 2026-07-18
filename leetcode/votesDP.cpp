#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {

    long long numberOfCombToWin(vector<pair<string, int>> cities) {

        int total_votes = 0;
        int i, j;

        for (auto &city : cities) {
            total_votes += city.second;
        }

        int n = cities.size();
        
        // FIX: Changed DP table type to long long.
        // Re-aligned dimensions to dp[states][votes] for standard 0/1 knapsack implementation.
        vector<vector<long long>> dp(n + 1, vector<long long>(total_votes + 1, 0));

        // FIX: Corrected base case. There is exactly 1 way to get 0 votes using 0 states.
        dp[0][0] = 1; 

        // FIX: Restructured loops for 0/1 Knapsack (each state can only be chosen once).
        // Outer loop runs through states (1 to n), inner loop runs through vote totals (0 to total_votes).
        for (i = 1; i <= n; i++) {
            for (j = 0; j <= total_votes; j++) {
                // Option 1: Don't take the current state (inherit combinations from the first i-1 states)
                dp[i][j] = dp[i - 1][j];
                
                // Option 2: Take the current state (if the vote count j allows it)
                if (j - cities[i - 1].second >= 0) {
                    dp[i][j] += dp[i - 1][j - cities[i - 1].second];
                }
            }
        }

        long long final_ans = 0; // FIX: Changed to long long to prevent overflow

        for (i = total_votes / 2 + 1; i <= total_votes; i++) {
            final_ans += dp[n][i]; // FIX: Collected the results from the final state row (index n)
        }

        return final_ans;
    }
  

    // State optimisation V2
    long long numberOfCombToWinV2(vector<pair<string, int>> cities) {

        int total_votes = 0;
        int i, j;

        for (auto &city : cities) {
            total_votes += city.second;
        }

        int n = cities.size();
        
        // O(total_votes) space
        vector<long long> dp(total_votes+1,0), dp2(total_votes+1,0);

        dp2[0] = 1; 

        // FIX: Restructured loops for 0/1 Knapsack (each state can only be chosen once).
        // Outer loop runs through states (1 to n), inner loop runs through vote totals (0 to total_votes).
        for (i = 1; i <= n; i++) {
            for (j = 0; j <= total_votes; j++) {
                // Option 1: Don't take the current state (inherit combinations from the first i-1 states)
                dp[j] = dp2[j];
                
                // Option 2: Take the current state (if the vote count j allows it)
                if (j - cities[i - 1].second >= 0) {
                    dp[j] += dp2[j - cities[i - 1].second];
                }
            }
            dp2 = dp;// update prev
        }

        long long final_ans = 0; // FIX: Changed to long long to prevent overflow

        for (i = total_votes / 2 + 1; i <= total_votes; i++) {
            final_ans += dp[i]; // FIX: Collected the results from the final state row (index n)
        }

        return final_ans;
    }

    // state optimisation v3
    long long numberOfCombToWinV3(vector<pair<string, int>> cities) {

        int total_votes = 0;
        int i, j;

        for (auto &city : cities) {
            total_votes += city.second;
        }

        int n = cities.size();
        
        // O(total_votes) space
        vector<long long> dp(total_votes+1,0);

        dp[0] = 1; 

        for (i = 1; i <= n; i++) {
            for (j = total_votes; j>= cities[i-1].second;j--) {
                dp[j] += dp[j - cities[i - 1].second]; // much cleaner now
            }
        }

        long long final_ans = 0; // FIX: Changed to long long to prevent overflow

        for (i = total_votes / 2 + 1; i <= total_votes; i++) {
            final_ans += dp[i]; // FIX: Collected the results from the final state row (index n)
        }

        // TC: O(total_votes*N)
        // SC: O(total_votes)
        return final_ans;
    }
};
