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
public: // FIX: Added public access specifier so the method can be called externally

    // FIX: Changed return type to bool since it returns true/false
    bool isPossibleToSplit(vector<int> arr) {
        int n = arr.size();
        
        // FIX: Added a guard condition. We need at least 3 elements to remove 1 
        // and split the remaining into 2 non-empty sections.
        if (n < 3) return false; 

        // FIX: Changed maps to unordered_sets because we only need to check for existence
        unordered_set<int> prefix_seen, seen_els;

        int total_sum = 0;
        for(auto a: arr){
            total_sum += a;
        }

        int i;
        int prefix = 0;

        for(i = 0; i < n; i++) {

            // --- Case 1: i is the removed element (Split point k is before i) ---
            // FIX: Removed the restrictive 'i < n - 2' constraint. 
            // FIX: Added a parity check to ensure the remaining sum is even.
            if ((total_sum - arr[i]) % 2 == 0) {
                // FIX: Corrected the math formula to target exactly half of the remaining sum
                int temp = (total_sum - arr[i]) / 2;
                if(prefix_seen.count(temp)){
                    return true;
                }
            }

            prefix += arr[i];
            seen_els.insert(arr[i]); // FIX: Used .insert() for unordered_set

            // --- Case 2: i is the split point K (Removed element is at or before i) ---
            // FIX: Adjusted bounds to 'i >= 1 && i <= n - 2' to ensure both the left 
            // and right sections retain at least 1 element after removal.
            if(i >= 1 && i <= n - 2){ 
                int temp = 2 * prefix - total_sum;
                if(seen_els.count(temp)){
                    return true;
                }
            }

            // FIX: Instead of adding all prefixes blindly, we only store the prefix if 
            // it leaves at least 1 element for the right side in Case 1 (meaning k <= n - 3).
            if (i <= n - 3) {
                prefix_seen.insert(prefix);
            }
        }

        return false;
    }
};
