class Solution {
public:
    vector<int> lastseen;
    vector<int> prev;
    int mod = 1e9 + 7;
    int dp[5000];
    int fn(int n) {
        if (n == 0)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int total = ((fn(n - 1) * 2)) % mod;

        int duplicate = 0;
        if (prev[n] != 0) {

            duplicate = fn(prev[n] - 1);
            total = (total - duplicate + mod) % mod;
        }

        return dp[n] = total;
    }
    int distinctSubseqII(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        lastseen.resize(26 + 1, 0);
        prev.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int idx = s[i - 1] - 'a';
            prev[i] = lastseen[idx];
            lastseen[idx] = i;
        }
        return (fn(n) - 1 + mod )%mod;
    }
};