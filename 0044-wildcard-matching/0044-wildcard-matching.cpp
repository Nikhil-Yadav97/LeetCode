class Solution {
public:
    bool isMatch(string s, string p) {

        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[n][m] = true;
        for (int j = m - 1; j >= 0; j--) {
            if (p[j] == '*')
                dp[n][j] = dp[n][j + 1];
            else
                dp[n][j] = false;
        }
        for (int ind1 = n - 1; ind1 >= 0; ind1--) {
            for (int ind2 = m - 1; ind2 >= 0; ind2--) {
                if (s[ind1] == p[ind2] || p[ind2] == '?')
                    dp[ind1][ind2] = dp[ind1 + 1][ind2 + 1];
                else if (p[ind2] == '*')
                    dp[ind1][ind2] =
                        dp[ind1 ][ind2 + 1] || dp[ind1 + 1][ind2];
            }
        }
        return dp[0][0];
    }
};