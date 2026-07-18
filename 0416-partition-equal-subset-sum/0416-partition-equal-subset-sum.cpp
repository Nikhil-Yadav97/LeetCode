class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum = accumulate(begin(nums), end(nums), 0);
        if (totalsum % 2)
            return false;
        int t = totalsum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(t + 1, false));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int target = 0; target <= t; target++) {
                bool take = false;
                if (target - nums[ind] >= 0)
                    take = dp[ind + 1][target - nums[ind]];
                dp[ind][target] = take || dp[ind + 1][target];
            }
        }
        return dp[0][t];
    }
};