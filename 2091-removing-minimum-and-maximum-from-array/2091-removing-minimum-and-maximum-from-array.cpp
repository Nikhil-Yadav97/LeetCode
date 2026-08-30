class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min_index = 0, max_index = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[min_index] > nums[i])
                min_index = i;
            if (nums[max_index] < nums[i])
                max_index = i;
        }

        int minoper =
            min(max(min_index, max_index)+1, n - min(min_index, max_index));

        minoper = min({minoper, min(min_index, max_index)+1 + n -
                                    max(min_index, max_index)});
        return minoper ;
    }
};