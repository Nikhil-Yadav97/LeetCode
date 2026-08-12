class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        vector<tuple<int, int, int>> merge;
        int n = startTime.size();
        for (int i = 0; i < n; i++) {
            merge.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(begin(merge), end(merge));
        vector<int> dp(n + 1, 0);
        for (int i = n-1; i >= 0; i--) {
            int nottake = dp[i+1];
            auto [st, ed, value] = merge[i];
            int take = value;
            auto j = lower_bound(begin(merge), end(merge),
                                 make_tuple(ed, INT_MIN, INT_MIN)) -
                     merge.begin();
            take += dp[j];
            dp[i]= max(take, nottake);
        }

        return dp[0];
    }
};