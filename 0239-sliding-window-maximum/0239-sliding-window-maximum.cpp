class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int i = 0, n = nums.size();
        vector<int> ans;
        while (i < n) {
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            int lindex = i - k;
            while (dq.front() <= lindex) {
                dq.pop_front();
            }
            if (i +1 >= k)
                ans.push_back(nums[dq.front()]);
            i++;
        }
        return ans;
    }
};