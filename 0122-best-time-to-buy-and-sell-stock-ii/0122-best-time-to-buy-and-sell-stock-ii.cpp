class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int sell = 0; sell <= 1; sell++) {
                if (sell)
                    dp[ind][sell]= max(-prices[ind] + dp[ind+1][0],
                               dp[ind+1][1]);
                else
                dp[ind][sell]= max(prices[ind] + dp[ind+1][1],
                           dp[ind+1][0]);
            }
        }
        return dp[0][1];
    }
};