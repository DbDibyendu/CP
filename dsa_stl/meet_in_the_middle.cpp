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

#define display(A)                                                             \
  for (auto &aa : A)                                                           \
    cout << aa << ' ';                                                         \
  cout << endl;

#define read(A)                                                                \
  for (auto &aa : A) {                                                         \
    cin >> aa;                                                                 \
  }
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
//=======================
//
const int MOD = 1000000007;
const int N = 1000007, M = N;
//=======================

class Solution {
public:
  // Function to generate all subset sums of a given half
  vector<int> getSubsetSums(const vector<int> &arr) {
    int n = arr.size();
    vector<int> result;
    for (int mask = 0; mask < (1 << n); ++mask) {
      int sum = 0;
      for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
          sum += arr[i];
        }
      }
      result.push_back(sum);
    }
    return result;
  }

  int closestSubsetSum(vector<int> &nums, int target) {
    int n = nums.size();

    // Step 1: Split the array into two halves
    vector<int> left(nums.begin(), nums.begin() + n / 2);
    vector<int> right(nums.begin() + n / 2, nums.end());

    // Step 2: Generate all subset sums for both halves
    vector<int> leftSums = getSubsetSums(left);
    vector<int> rightSums = getSubsetSums(right);

    // Step 3: Sort one side for binary search (right side here)
    sort(rightSums.begin(), rightSums.end());

    // Step 4: Try all leftSums and binary search in rightSums
    int closest = INT_MAX;
    for (int lsum : leftSums) {
      int rem = target - lsum;

      // Lower_bound gives us the smallest element >= rem
      auto it = lower_bound(rightSums.begin(), rightSums.end(), rem);

      // Check element at 'it' and 'it - 1' for closest match
      if (it != rightSums.end()) {
        int total = lsum + *it;
        closest = min(closest, abs(target - total));
      }
      if (it != rightSums.begin()) {
        --it;
        int total = lsum + *it;
        closest = min(closest, abs(target - total));
      }
    }

    return closest;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {3, 9, 7, 3};
  int target = 10;
  cout << "Closest Subset Sum Difference: "
       << sol.closestSubsetSum(nums, target) << endl;
  return 0;
}
