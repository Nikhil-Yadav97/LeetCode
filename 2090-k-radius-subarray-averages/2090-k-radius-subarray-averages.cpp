class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int lind = (i - k) >= 0 ? i - k : -1;
            int rind = (i + k) < n ? i + k : -1;
            if (lind == -1 || rind == -1)
                ans.push_back(-1);
            else {
                long long left = 0;
                if (lind > 0)
                    left = prefix[lind - 1];

                ans.push_back((prefix[rind] - left) / (2*k+1));
            }
        }
        return ans;
    }
};