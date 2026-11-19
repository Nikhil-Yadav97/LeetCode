class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        return min({
            nums[n-1] - nums[2],  // Change 2 smallest
            nums[n-2] - nums[1],  // Change 1 smallest, 1 largest
            nums[n-3] - nums[0]   // Change 2 largest
        });
    }
};