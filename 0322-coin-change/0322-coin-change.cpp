class Solution {
public:
    int n;
    int coinChange(vector<int>& coins, int amt) {
        n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amt + 1, 1e9));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int amount = 1; amount <= amt; amount++) {
                int take = 1e9;
                if (amount - coins[ind] >= 0)
                    take = 1 + dp[ind][amount - coins[ind]];

                dp[ind][amount] = min(take, dp[ind + 1][amount]);
            }
        }
        int coincount = dp[0][amt];
        return coincount == 1e9 ? -1 : coincount;
    }
};