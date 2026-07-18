class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int k = 0; k < 4; k++) {
                if (k % 2)
                    dp[ind][k] =
                        max(prices[ind] + dp[ind + 1][k + 1], dp[ind + 1][k]);
                else
                    dp[ind][k] =
                        max(-prices[ind] + dp[ind + 1][k + 1], dp[ind + 1][k]);
            }
        }
        return dp[0][0];
    }
};