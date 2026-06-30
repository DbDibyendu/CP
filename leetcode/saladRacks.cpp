

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



// dp[x][y] stores the min racks for x machines of Type X and y machines of Type Y
int dp[105][105]; 

// O(N^2)
int solveRacks(int x, int y) {
    if (x == 0 && y == 0) return 0;
    if (dp[x][y] != -1) return dp[x][y];

    int ans = 1e9;

    // Iterate through all possible combinations (i, j) we can pack into ONE single rack
    // Max possible X in a rack is 3 (3*3 <= 10). Max possible Y is 3 (3*3 <= 10).
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            if (i == 0 && j == 0) continue; // Must place at least one machine
            
            // Check if this combination fits the rack constraints (scaled down by 100)
            if (3 * i + 1 * j <= 10 && 2 * i + 3 * j <= 10) {
                if (x >= i && y >= j) {
                    ans = min(ans, 1 + solveRacks(x - i, y - j));
                }
            }
        }
    }

    return dp[x][y] = ans;
}

int solve(int n, vector<vector<int>> nums) {
    int x = 0, y = 0;
    for (auto const& machine : nums) {
        if (machine[0] == 300) {
            x++;
        } else {
            y++;
        }
    }

    memset(dp, -1, sizeof(dp));
    return solveRacks(x, y);
}


// follow up 2
// try each and then back track for max returns


int solveRacks2(vector<int> &taken,int capX, int capY, vector<vector<int>> &nums, int count) {

  int i,j;

  if(count == nums.size()) return 0;

  int ans = 1e9;
  for(i = 0;i<nums.size();i++){
    if(taken[i] == 0){

      // try taking
      taken[i] = 1;
      
      if(nums[i][0] <= capX && nums[i][1] <= capY){
        ans = min(ans, solveRacks2(taken, capX - nums[i][0], capY - nums[i][1], nums, count+1));
      }else{
        // try new
        ans = min(ans, 1+solveRacks2(taken, 1000 - nums[i][0], 1000 - nums[i][1], nums, count+1));
      }
      taken[i] = 0;
    }
  }

  return ans;
}

int solve2(int n, vector<vector<int>> nums) {
    int x = 0, y = 0;

    memset(dp, -1, sizeof(dp));
    vector<int>taken(n, 0);
    return solveRacks2(taken, 1000, 1000, nums, 0);
}

int main() {
    // Example: 3 machines of [300, 200] and 3 machines of [100, 300]
    vector<vector<int>> machines = {{300, 200}, {300, 200}, {300, 200}, {100, 300}, {100, 300}, {100, 300}};
    cout << "Min Racks Required: " << solve(machines.size(), machines) << endl; 
    return 0;
}
