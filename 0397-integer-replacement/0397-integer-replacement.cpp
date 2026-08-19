class Solution {
public:
    map<int, int> dp;
    int fn(long long n) {
        if (n == 1)
            return 0;

        if (dp.find(n) != dp.end())
            return dp[n];

        if (n % 2 == 0)
            return dp[n] = 1 + fn(n / 2);
        return dp[n] = 1 + min(fn(n - 1), fn(n + 1));
    }
    int integerReplacement(int n) {
        dp.clear();
        return fn(n);
    }
};