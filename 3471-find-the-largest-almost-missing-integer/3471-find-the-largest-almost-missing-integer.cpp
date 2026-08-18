class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int, int> window;
        map<int, int> count;
        int n = nums.size();
        if (n < k)
            return -1;
        for (int i = 0; i < k; i++) {
            window[nums[i]]++;
        }
        for (auto [ele, cnt] : window) {
            count[ele]++;
        }

        for (int i = k; i < n; i++) {
            window[nums[i - k]]--;

            if (window[nums[i - k]] == 0)
                window.erase(nums[i - k]);

            window[nums[i]]++;

            for (auto [ele, freq] : window) {
                count[ele]++;
            }
        }

        int ans = -1;
        for (auto [ele, cnt] : count) {
            if (cnt == 1)
                ans = max(ans, ele);
        }
        return ans;
    }
};