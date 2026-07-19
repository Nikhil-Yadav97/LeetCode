class Solution {
public:
    bool check(string &s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
         vector<int> dp(n + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--) {
            int mini = 1e9;
            for (int i = ind; i < s.size(); i++) {
                if (check(s, ind, i)) {
                    mini = min(mini, dp[i+1] + 1);
                }
            }
            dp[ind] = mini;
        }
        return dp[0] - 1;
    }
};