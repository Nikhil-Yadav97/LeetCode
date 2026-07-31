class Solution {
public:
    vector<int> dp;
    long long fn(int ind, vector<int>& nums, int k,
                 vector<vector<int>>& helper) {
        if (ind >= nums.size())
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        long long mini = LLONG_MAX;

        for (int i = ind; i < nums.size(); i++) {
            int value = helper[ind][i] + k;
            mini = min(mini, value + fn(i + 1, nums, k, helper));
        }
        return dp[ind] = mini;
    }
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        dp.resize(n + 1, -1);
        vector<vector<int>> helper(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {

            map<int, int> mpp;
            int count = 0;
            for (int j = i; j < n; j++) {
                if (mpp.count(nums[j])) {
                    if (mpp[nums[j]]== 1)
                        count += 2;
                    else
                        count++;
                }
                mpp[nums[j]]++;
                helper[i][j] = count;
            }
        }

        return (int)fn(0, nums, k, helper);
    }
};