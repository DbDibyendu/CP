class Solution {
public:

 // tails i stores the smallest possible ending value of an increasing
    // subsequence of length i.

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> tails;        // stores values
        vector<int> tailIndex;    // stores index in nums
        vector<int> parent(n, -1);
       // position of element in LIS

        // for each x -> find it's optimal place in the tails vector.

        for (int i = 0; i < n; i++) {

            int x = nums[i];

            auto it = lower_bound(tails.begin(), tails.end(), x);
            int idx = it - tails.begin();

            // if element is greater than all tails, push_back
            if (it == tails.end()) {
                tails.push_back(x);
                tailIndex.push_back(i);
            } else {
                // else replace tail at pos x by better value
                *it = x;
                tailIndex[idx] = i;
            }

            // link to previous element in LIS
            if (idx > 0) {
                parent[i] = tailIndex[idx - 1];
            }
        }

        // reconstruct LIS
        vector<int> lis;
        int cur = tailIndex.back();

        while (cur != -1) {
            lis.push_back(nums[cur]);
            cur = parent[cur];
        }

        reverse(lis.begin(), lis.end());

        // for(auto l: lis){
        //     cout<<l<<endl;
        // }
        return tails.size();
    }
};
