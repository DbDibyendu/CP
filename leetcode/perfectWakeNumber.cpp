#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

// mask is important to not repeat number
// dp[pos][mask][lastDigit][state][tight]
// pos: up to 10 digits (for 10^9)
// mask: 1 << 10 (tracks digits 0-9 to ensure uniqueness)
// lastDigit: 0-9
// state: 0 (leading zeros), 1 (increasing), 2 (decreasing)
// tight: 0 or 1
int dp[11][1024][10][3][2];

int recur(int pos, int mask, int lastDigit, int state, int tight, const string &s) {
    if (pos == s.length()) {
        // If state > 0, it means we placed at least one valid non-zero digit
        return (state > 0); 
    }
    
    if (dp[pos][mask][lastDigit][state][tight] != -1) {
        return dp[pos][mask][lastDigit][state][tight];
    }
    
    int limit = tight ? (s[pos] - '0') : 9;
    int tot = 0;
    
    // Case 1: Stay in leading zeros (only valid if we haven't started a number yet)
    if (state == 0) {
        tot += recur(pos + 1, mask, 0, 0, tight && (0 == limit), s);
    }
    
    // Case 2: Try placing a digit from 1 to limit (0 is forbidden by the problem rules)
    for (int d = 1; d <= limit; d++) {
        // Rule 1: No repeated digits
        if (mask & (1 << d)) continue;
        
        if (state == 0) {
            // Placing the very first digit starts the 'increasing' phase
            tot += recur(pos + 1, mask | (1 << d), d, 1, tight && (d == limit), s);
        } 
        else if (state == 1) {
            // Currently increasing
            if (d > lastDigit) {
                // Keep increasing
                tot += recur(pos + 1, mask | (1 << d), d, 1, tight && (d == limit), s);
            } else if (d < lastDigit) {
                // Peak reached! Transition to decreasing phase
                tot += recur(pos + 1, mask | (1 << d), d, 2, tight && (d == limit), s);
            }
            // Note: d == lastDigit is ignored because digits must be strictly monotonic
        } 
        else if (state == 2) {
            // Currently decreasing (cannot go back up)
            if (d < lastDigit) {
                tot += recur(pos + 1, mask | (1 << d), d, 2, tight && (d == limit), s);
            }
        }
    }
    
    return dp[pos][mask][lastDigit][state][tight] = tot;
}

int solve(int N) {
    string s = to_string(N);
    memset(dp, -1, sizeof(dp));
    
    // Start at position 0, empty mask (0), lastDigit 0, state 0 (leading zeros), and tight = 1
    return recur(0, 0, 0, 0, 1, s);
}

int main() {
    // Example test case: N = 20
    // Valid numbers: 1,2,3,4,5,6,7,8,9, 12,13,14,15,16,17,18,19
    // (10 has 0, 11 repeats 1)
    cout << solve(20) << endl; // Output: 17
    return 0;
}
