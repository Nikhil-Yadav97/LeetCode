class Solution {
public:
    vector<int> prefix;

    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        prefix.resize(n, 0);
        prefix[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }
        vector<int> dp(n + 1, 0);
        dp[n - 1] = prefix[n - 1];
        for (int i = n - 2; i >= 1; i--) {

            int take = prefix[i] - dp[i + 1];
            int nottake = dp[i + 1];

            dp[i] = max(take, nottake);
        }
        return dp[1];
    }
};