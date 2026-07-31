class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0;
        long long maxsum = 0, sum = 0;
        map<int, int> mpp;
        while (r < n) {
            mpp[nums[r]]++;
            sum += nums[r];
            while (r - l + 1 > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0)
                    mpp.erase(nums[l]);
                sum -= nums[l];
                l++;
            }
            if ((r - l + 1) == k && mpp.size() == k)
                maxsum = max(maxsum, sum);

            r++;
        }
        return maxsum;
    }
};