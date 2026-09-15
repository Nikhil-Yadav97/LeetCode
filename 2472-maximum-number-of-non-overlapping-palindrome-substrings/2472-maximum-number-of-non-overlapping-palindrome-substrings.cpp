class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        vector<vector<bool>> pal(n+1,vector<bool> (n+1,false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 1 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }
        for (int ind = n - 1; ind >= 0; ind--) {
            int maxcount = dp[ind + 1];
            for (int i = ind; i < s.size(); i++) {
                if ((i - ind + 1 >= k) && pal[ind][i])
                    maxcount = max(maxcount, 1 + dp[i + 1]);
            }
            dp[ind] = maxcount;
        }
        return dp[0];
    }
};