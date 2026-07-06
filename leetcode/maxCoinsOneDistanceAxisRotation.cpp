#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// if movement direction in 8 different direction allowed
class MoonLandingWarmUp {
public:
    int maxCoinsWarmUp(const vector<vector<int>>& coins, int k) {
        int n = coins.size();
        if (n == 0) return 0;

        // 1. Build the 2D Prefix Sum Matrix (1-indexed to avoid out-of-bounds padding checks)
        vector<vector<int>> P(n + 1, vector<int>(n + 1, 0));
        for (int r = 1; r <= n; ++r) {
            for (int c = 1; c <= n; ++c) {
                P[r][c] = coins[r-1][c-1] 
                        + P[r-1][c] 
                        + P[r][c-1] 
                        - P[r-1][c-1];
            }
        }

        int max_total_coins = 0;

        // 2. Scan every possible landing site (r, c)
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                
                // Define the bounding box of our reachable square, clamped to grid edges
                int r1 = max(0, r - k);
                int c1 = max(0, c - k);
                int r2 = min(n - 1, r + k);
                int c2 = min(n - 1, c + k);

                // Convert to our 1-indexed Prefix Matrix coordinates
                int row1 = r1 + 1, col1 = c1 + 1;
                int row2 = r2 + 1, col2 = c2 + 1;

                // O(1) Region Query
                int current_coins = P[row2][col2] 
                                  - P[row1 - 1][col2] 
                                  - P[row2][col1 - 1] 
                                  + P[row1 - 1][col1 - 1];

                max_total_coins = max(max_total_coins, current_coins);
            }
        }

        return max_total_coins;
    }


    int maxCoinsWarmUpV2(const vector<vector<int>>& coins, int k) {
        int n = coins.size();
        if (n == 0) return 0;

        vector<vector<int>> rotate_grid(2*n, vector<int>(2*n, 0));

        for(int x=0;x<n;x++){
          for(int y=0;y<n;y++){

            int u = x+y;
            int v = x-y + n-1;
            rotate_grid[u][v] = coins[x][y];
          }
        }

        // 1. Build the 2D Prefix Sum Matrix (1-indexed to avoid out-of-bounds padding checks)
        vector<vector<int>> P(2*n + 1, vector<int>(2*n + 1, 0));
        for (int r = 1; r <= 2*n; ++r) {
            for (int c = 1; c <= 2*n; ++c) {
                P[r][c] = rotate_grid[r-1][c-1] 
                        + P[r-1][c] 
                        + P[r][c-1] 
                        - P[r-1][c-1];
            }
        }

        int max_total_coins = 0;

        // 2. Scan every possible landing site (r, c)
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                
                int r = x+y;
                int c = x-y + n-1;

                // Define the bounding box of our reachable square, clamped to grid edges
                int r1 = max(0, r - k);
                int c1 = max(0, c - k);
                int r2 = min(2*n - 1, r + k);
                int c2 = min(2*n - 1, c + k);

                // Convert to our 1-indexed Prefix Matrix coordinates
                int row1 = r1 + 1, col1 = c1 + 1;
                int row2 = r2 + 1, col2 = c2 + 1;

                // O(1) Region Query
                int current_coins = P[row2][col2] 
                                  - P[row1 - 1][col2] 
                                  - P[row2][col1 - 1] 
                                  + P[row1 - 1][col1 - 1];

                max_total_coins = max(max_total_coins, current_coins);
            }
        }
        return max_total_coins;
    }
};


// If direction in 4 direction allowed, then it becomes interesting but just the same
// Just rotate about 45 degree
//       [Up 2]
//    [.]  [.]  [.]
// [L2] [.] [S] [.] [R2]
//    [.]  [.]  [.]
//      [Down 2]


