class Solution {
public:
    int first(vector<int>& nums, int target, int low, int high) {
        int ans = -1;
        while (low <= high) {

            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                ans = mid;
                high = mid - 1;
            } else {
                if (nums[mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return ans;
    }
    int last(vector<int>& nums, int target, int low, int high) {
        int ans = -1;
        while (low <= high) {

            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                ans = mid;
                low = mid + 1;
            } else {
                if (nums[mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return ans;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int firstocc = first(nums, target, 0, nums.size() - 1);
        int lastocc = last(nums, target, 0, nums.size() - 1);
        if (lastocc == -1 && firstocc == -1) {
            return ans;
        }
        for (int i = firstocc; i <= lastocc; i++)
            ans.push_back(i);
        return ans;
    }
};