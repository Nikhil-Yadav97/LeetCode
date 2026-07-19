class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for (int ind = n - 1; ind >= 0; ind--) {
            int mini = 0;
            int maxi = arr[ind];
            int limit = min((int)arr.size(), ind + k);
            for (int i = ind; i < limit; i++) {
                maxi = max(maxi, arr[i]);
                mini = max(mini, (i - ind + 1) * maxi + dp[i+1]);
            }
            dp[ind]= mini;
        }
        return dp[0];
    }
};