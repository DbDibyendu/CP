#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

//===============================
// DIGIT DP OVERVIEW:
//===============================
// Use when you're asked to count numbers in a range [L, R] with digit-level
// constraints:
// - Constraints like "number must end in a substring", or "no digit > K", etc.
// - We build the number one digit at a time, keeping track of how far we’ve
// matched and if the current number is bounded or not.
//
// Key Parameters:
// 1. `idx`: current digit index in the number
// 2. `larger`: whether the current number has already become smaller than the
// upper bound (relaxes future choices)
// 3. `limit`: restricts the max digit value allowed at each position
// 4. Matching suffix logic is applied based on right alignment of `s`
//===============================

//===============================
// TIME COMPLEXITY: O(#digits * 2)
// Since we only track: position idx (up to 20), and larger (2 states)
// and we memoize results with dp table.
// No loop on digits as digits are from input string.
//
// SPACE COMPLEXITY: O(22 * 2 * 11) = ~500 states
// Because dp[idx][limit][larger] has:
// - idx: up to 20
// - limit: up to 10
// - larger: 0/1
//===============================

class Solution {
public:
  // dp[idx][limit][larger] — memoization table
  long long dp[22][11][2];

  // Digit DP Recursive Function
  // toMatchS = the suffix we must match
  // range = upper bound number (as string)
  // limit = max allowed digit
  // idx = current digit index in the range
  // larger = whether the number so far is already smaller than range
  long long recur(const string &toMatchS, const string &range, long long limit,
                  int idx, bool larger) {

    int m = toMatchS.length();
    int r = range.length();

    // Base case: if number is too short, can't be valid
    if (r < m)
      return 0;
    if (idx == r)
      return 0; // done processing all digits

    if (dp[idx][limit][larger] != -1) {
      return dp[idx][limit][larger];
    }

    long long res = 0;

    if (larger) {
      // Already smaller → can freely pick any digit ≤ limit
      if (r - idx <= m) {
        // We're at suffix alignment — 1 match possible
        res = 1;
      } else {
        // Not yet at suffix → recurse on all (limit + 1) digit choices
        res = (limit + 1) * recur(toMatchS, range, limit, idx + 1, 1);
      }
    } else {
      // Still matching the upper bound → digit constraint applies
      if (r - idx <= m) {
        // In suffix range
        int sIdx = m - r + idx; // Align toMatchS from the right
        if (sIdx < 0)
          return 0;
        if (sIdx >= m)
          return 1;

        int curDigit = range[idx] - '0';
        int targetDigit = toMatchS[sIdx] - '0';

        if (curDigit > targetDigit) {
          res = 1;
        } else if (curDigit == targetDigit) {
          res = recur(toMatchS, range, limit, idx + 1, 0);
        } else {
          res = 0;
        }
      } else {
        int digit = range[idx] - '0';
        if (limit + 1 <= digit) {
          // If limit fully within [0..digit], all choices go to larger path
          res += (limit + 1) * recur(toMatchS, range, limit, idx + 1, 1);
        } else {
          // Consider [0..digit-1] under larger path
          res += (digit)*recur(toMatchS, range, limit, idx + 1, 1);
          // digit == range[idx] → stay bounded
          res += recur(toMatchS, range, limit, idx + 1, 0);
        }
      }
    }

    return dp[idx][limit][larger] = res;
  }

  // Wrapper function to compute number of powerful integers in range
  long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                string s) {
    // Count numbers in [0..finish]
    memset(dp, -1, sizeof(dp));
    long long fCount = recur(s, to_string(finish), limit, 0, 0);

    // Count numbers in [0..start-1]
    memset(dp, -1, sizeof(dp));
    long long sCount = recur(s, to_string(start - 1), limit, 0, 0);

    // Answer is difference
    return fCount - sCount;
  }
};

//===============================
// Example driver (not used in contests)
//===============================

void solve() {
  long long start, finish;
  int limit;
  string s;

  cin >> start >> finish >> limit >> s;

  Solution sol;
  cout << sol.numberOfPowerfulInt(start, finish, limit, s) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
