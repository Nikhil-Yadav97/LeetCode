class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 1);
        for (int ind = 0; ind < n; ind++) {
            for (int prev = 0; prev < ind; prev++) {
                if (nums[prev] < nums[ind])
                    dp[ind] = max(1 + dp[prev], dp[ind]);
                
            }
        }
        return *max_element(begin(dp),end(dp));
    }
};