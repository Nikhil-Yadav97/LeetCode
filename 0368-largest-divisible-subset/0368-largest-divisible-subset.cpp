class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        vector<long long> dp(n + 1, 1);
        vector<long long> path(n);
        for (int i = 0; i < n; i++)
            path[i] = i;
        int maxind = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < 1 + dp[j]) {
                        path[i] = j;
                        dp[i] = 1 + dp[j];
                        if (dp[maxind] < dp[i])
                            maxind = i;
                    }
                }
            }
        }
        vector<int> ans;
        int i = maxind;
        while (path[i] != i) {
            ans.push_back(nums[i]);
            i = path[i];
        }
        ans.push_back(nums[i]);
        reverse(begin(ans), end(ans));
        return ans;
    }
};