class Solution {
public:

    pair<int,int> dp[2505];
    bool vis[2505];

    pair<int,int> recur(int i, vector<int>& nums) {

        if (vis[i]) {
            return dp[i];
        }

        int bestLen = 1;   // at least [nums[i]]
        int ways = 1;      // single element subsequence

        for (int j = i + 1; j < nums.size(); j++) {

            if (nums[j] > nums[i]) {

                auto nxt = recur(j, nums);

                int len = 1 + nxt.first;

                if (len > bestLen) {
                    bestLen = len;
                    ways = nxt.second;
                }
                else if (len == bestLen) {
                    ways += nxt.second;
                }
            }
        }

        vis[i] = true;
        return dp[i] = {bestLen, ways};
    }

    int findNumberOfLIS(vector<int>& nums) {

        memset(vis, 0, sizeof(vis));

        int maxLen = 0;
        int totalWays = 0;

        for (int i = 0; i < nums.size(); i++) {

            auto res = recur(i, nums);

            if (res.first > maxLen) {
                maxLen = res.first;
                totalWays = res.second;
            }
            else if (res.first == maxLen) {
                totalWays += res.second;
            }
        }

        return totalWays;
    }
};
