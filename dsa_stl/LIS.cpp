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

/*
    Longest Increasing Subsequence (LIS)

    Problem:
    Given an array of integers, find the length of the longest increasing
   subsequence (LIS).

    Example:
    Input:  nums = [10, 9, 2, 5, 3, 7, 101, 18]
    Output: 4
    Explanation: The LIS is [2, 3, 7, 101]
*/

// -------------------------------------
// ✅ Approach 1: DP - O(n^2) Time
// -------------------------------------
int lengthOfLIS_DP(vector<int> &nums) {
  int n = nums.size();
  vector<int> dp(n, 1); // dp[i] stores length of LIS ending at index i

  /*
      For each index i, check all previous elements j < i.
      If nums[j] < nums[i], try to extend the LIS ending at j.
  */
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (nums[j] < nums[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  return *max_element(dp.begin(), dp.end());
}

/*
    Time Complexity: O(n^2)
    Space Complexity: O(n)
*/

// -------------------------------------
// ✅ Approach 2: Binary Search - O(n log n) Time
// -------------------------------------
int lengthOfLIS_BinarySearch(vector<int> &nums) {
  vector<int> tails;

  /*
      tails[i] = the smallest possible tail of an increasing subsequence of
     length i+1.

      We do a binary search (lower_bound) to find the position of the current
     number. If it's greater than all tails, we append it (i.e., extend the
     LIS). Otherwise, we replace the first element in tails >= current number.
  */
  for (int num : nums) {
    auto it = lower_bound(tails.begin(), tails.end(), num);

    if (it == tails.end()) {
      tails.push_back(num); // extend LIS
    } else {
      *it = num; // replace to maintain minimal tail
    }
  }

  return tails.size();
}

/*
    Time Complexity: O(n log n)
    Space Complexity: O(n)
*/

int main() {
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

  cout << "LIS Length (DP): " << lengthOfLIS_DP(nums) << endl;
  cout << "LIS Length (Binary Search): " << lengthOfLIS_BinarySearch(nums)
       << endl;

  return 0;
}
