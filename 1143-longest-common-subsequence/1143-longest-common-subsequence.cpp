class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size(), m = t2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int ind1 = n - 1; ind1 >= 0; ind1--) {
            for (int ind2 = m - 1; ind2 >= 0; ind2--) {
                if (t1[ind1] == t2[ind2])
                    dp[ind1][ind2] = 1 + dp[ind1 + 1][ ind2 + 1];

                dp[ind1][ind2] =
                    max({dp[ind1][ind2], dp[ind1 + 1][ind2],
                         dp[ind1] [ind2 + 1]});
            }
        }
        return dp[0][0];
    }
};