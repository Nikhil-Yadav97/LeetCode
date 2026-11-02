class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int value, count = 0, n = nums.size();

        value = nums[n / 2];

        for (auto it : nums) {
            count += abs(it - value);
        }
        return count;
    }
};