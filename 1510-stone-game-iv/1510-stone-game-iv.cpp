class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                // if bob not able to build i-j*j then its true for alice
                dp[i] = dp[i - j * j] == false || dp[i];
            }
        }
        return dp[n];
    }
};