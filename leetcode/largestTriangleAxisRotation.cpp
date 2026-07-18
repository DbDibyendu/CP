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

    long long numberOfCombToWin(vector<vector<int>> arr) {

        int total_votes = 0;
        int i, j;

        // brute force 
        // O(n*m*n*m)

        // dp[i][j] = 1 + min(dp[i+1][j], dp[i][j+1])
        // 10 6 3 1
        // 6 1 1
        // 1 0
        // 1 0 
        //
        // 1 1 1
        // 1 1
        // 1
        //
        // 1 
        // 1 1
        // 1 1 1 
        //
        // suffix[i][j] = arr[i][j] + suffix[i][j-1] + suffix[i+1][j] - suffix[i+1][j-1];
        // O(m*n)
        // O(m)
        // 1 1 1
        //   1 1
        //     1
        //
        //     1
        //   1 1
        // 1 1 1
        //

        // just need the max side
        int max_side=0;
        int n  = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp1(n+1, vector<int>(m+1,0));
        vector<vector<int>> dp2(n+1, vector<int>(m+1,0));
        vector<vector<int>> dp3(n+1, vector<int>(m+1,0));
        vector<vector<int>> dp4(n+1, vector<int>(m+1,0));

        // some kind of min needs to be taken care of 
        // first triangle
        for(i=n-1;i>=0;i--){
          for(j=m-1;j>=0; j--){
            if(arr[i][j]){
              // 1 dimension can be reduced
              dp1[i][j] = 1 + min(dp1[i+1][j], dp1[i][j+1]);
              max_side = max(max_side, dp1[i][j]);
            }
          }
        }

        // 2nd triangle
        for(i=1;i<=n;i++){
          for(j=1;j<=m; j++){
            if(arr[i-1][j-1]){
              dp2[i][j] = 1 + min(dp2[i-1][j], dp2[i][j-1]);
              max_side = max(max_side, dp2[i][j]);
            }
          }
        }

        for(i=1;i<=n;i++){
          for(j=m-1;j>=0; j--){
            if(arr[i-1][j]){
              // min is imp
              dp3[i][j] = 1 + min(dp3[i-1][j], dp3[i][j+1]);
              max_side = max(max_side, dp3[i][j]);
            }
          }
        }

        for(i=n-1;i>=0;i--){
          for(j=1; j<=m; j++){
            if(arr[i][j-1]){
              dp4[i][j] = 1 + min(dp4[i+1][j], dp4[i][j-1]);
              max_side = max(max_side, dp4[i][j]);
            }
          }
        }

        // now also consider rotated indexes
        
        // axis rotation doesn't work here, due to introduced holes
        vector<vector<int>> arr2(2*n+1, vector<int>(2*m+1,0));


        return max_side*(max_side+1)/2;
    }
  

    long long numberOfCombToWinV2(vector<vector<int>> arr) {

        if (arr.empty() || arr[0].empty()) return 0;

        int i, j; // FIX: Removed unused total_votes variable
        int max_side = 0;
        int n = arr.size();
        int m = arr[0].size();

        // FIX: Changed DP vectors to size m+1 (columns) to align with the inner loop processing
        vector<int> dp1(m + 1, 0);
        vector<int> dp2(m + 1, 0);
        vector<int> dp3(m + 1, 0);
        vector<int> dp4(m + 1, 0);

        // 1st triangle orientation (Top-Left corner right-angle)
        for (i = n - 1; i >= 0; i--) {
            for (j = m - 1; j >= 0; j--) {
                if (arr[i][j]) {
                    // FIX: dp1[j] currently holds row i+1 data; dp1[j+1] holds current row i data
                    dp1[j] = 1 + min(dp1[j], dp1[j + 1]);
                    max_side = max(max_side, dp1[j]);
                } else {
                    dp1[j] = 0; // FIX: Crucial reset to prevent carrying over old data
                }
            }
        }

        // 2nd triangle orientation (Bottom-Right corner right-angle)
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                if (arr[i - 1][j - 1]) {
                    // FIX: dp2[j] holds row i-1 data; dp2[j-1] holds current row i data
                    dp2[j] = 1 + min(dp2[j], dp2[j - 1]);
                    max_side = max(max_side, dp2[j]);
                } else {
                    dp2[j] = 0; // FIX: Crucial reset
                }
            }
        }

        // 3rd triangle orientation (Bottom-Left corner right-angle)
        for (i = 1; i <= n; i++) {
            for (j = m - 1; j >= 0; j--) {
                if (arr[i - 1][j]) {
                    // FIX: dp3[j] holds row i-1 data; dp3[j+1] holds current row i data
                    dp3[j] = 1 + min(dp3[j], dp3[j + 1]);
                    max_side = max(max_side, dp3[j]);
                } else {
                    dp3[j] = 0; // FIX: Crucial reset
                }
            }
        }

        // 4th triangle orientation (Top-Right corner right-angle)
        for (i = n - 1; i >= 0; i--) {
            for (j = 1; j <= m; j++) {
                if (arr[i][j - 1]) {
                    // FIX: dp4[j] holds row i+1 data; dp4[j-1] holds current row i data
                    dp4[j] = 1 + min(dp4[j], dp4[j - 1]);
                    max_side = max(max_side, dp4[j]);
                } else {
                    dp4[j] = 0; // FIX: Crucial reset
                }
            }
        }

        return (long long)max_side * (max_side + 1) / 2;
    }

};
