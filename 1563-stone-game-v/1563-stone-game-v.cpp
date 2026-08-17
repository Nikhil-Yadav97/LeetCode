class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int st = 0; st + len <= n; st++) {
                int ed = st + len - 1;

                for (int mid = st + 1; mid <= ed; mid++) {
                    int s1 = prefix[mid] - prefix[st];
                    int s2 = prefix[ed + 1] - prefix[mid];

                    if (s1 == s2) {
                        dp[st][ed] = max(
                            dp[st][ed],
                            s1 + max(
                                dp[st][mid - 1],
                                dp[mid][ed]
                            )
                        );
                    }
                    else if (s1 > s2) {
                        dp[st][ed] = max(
                            dp[st][ed],
                            s2 + dp[mid][ed]
                        );
                    }
                    else {
                        dp[st][ed] = max(
                            dp[st][ed],
                            s1 + dp[st][mid - 1]
                        );
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};