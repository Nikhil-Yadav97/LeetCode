class Solution {
public:
    int change(int amt, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(amt + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int amount = 1; amount <= amt; amount++) {
                int take = 0;
                if (amount - coins[ind] >= 0)
                    take = dp[ind][amount - coins[ind]];

                dp[ind][amount] = take + dp[ind + 1][amount];
            }
        }
        return dp[0][amt];
    }
};