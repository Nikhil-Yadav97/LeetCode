class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            nums[i] = abs(nums[i]);
        n = (n + 1) / 2;
        sort(rbegin(nums), rend(nums));
        long long result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i < n)
                result += nums[i] * nums[i];
            else
                result -= nums[i] * nums[i];
        }
        return result;
    }
};