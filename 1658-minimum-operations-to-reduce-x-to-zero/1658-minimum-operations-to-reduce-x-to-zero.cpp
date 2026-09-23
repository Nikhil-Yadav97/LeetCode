class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), l = 0, r = 0;
        int total = accumulate(begin(nums), end(nums), 0);
        int req = total - x, sum = 0, len = INT_MIN;
        while (r < n) {
            sum += nums[r];
            while (l <= r && sum > req) {
                sum -= nums[l];
                l++;
            }
            if (sum == req)
                len = max(len, r - l + 1);

            r++;
        }
        if (len == INT_MIN)
            return -1;
        return n - len;
    }
};