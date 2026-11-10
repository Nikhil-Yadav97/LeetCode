class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 2, 0);
        dp[n + 1] = INT_MAX;
        for (int i = n-1; i >= 0; i--) {
            int oneStep = (costs[i] + 1) + dp[i + 1];
            int twoStep =
                (i + 2 <= n) ? (costs[i + 1] + 4) + dp[i + 2] : INT_MAX;
            int threeStep =
                (i + 3 <= n) ? (costs[i + 2] + 9) + dp[i + 3] : INT_MAX;

            dp[i] = min({oneStep, twoStep, threeStep});
        }
        return dp[0];
    }
};