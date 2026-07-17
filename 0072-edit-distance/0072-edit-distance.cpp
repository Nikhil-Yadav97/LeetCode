class Solution {
public:
    int minDistance(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][m] = n - i;

        for (int j = 0; j <= m; j++)
            dp[n][j] = m - j;

        for (int ind1 = n - 1; ind1 >= 0; ind1--) {
            for (int ind2 = m - 1; ind2 >= 0; ind2--) {
                if (s[ind1] == p[ind2])
                    dp[ind1][ind2] = dp[ind1 + 1][ind2 + 1];
                else
                    dp[ind1][ind2] =
                        1 + min({dp[ind1][ind2 + 1], dp[ind1 + 1][ind2],
                                 dp[ind1 + 1][ind2 + 1]});
            }
        }
        return dp[0][0];
    }
};