class Solution {
public:
    int fn(vector<int>& nums, int st, int n) {
        vector<int> dp(n + 2, 0);
        for (int i = n - 1; i >= st; i--) {
            dp[i] = max(dp[i + 2] + nums[i], dp[i + 1]);
        }
        return dp[st];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        return max(fn(nums, 0, n - 1), fn(nums, 1, n));
    }
};