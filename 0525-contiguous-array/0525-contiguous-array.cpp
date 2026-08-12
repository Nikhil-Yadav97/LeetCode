class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count = 0, maxlen = 0, n = nums.size();
        map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                count--;
            else
                count++;

            if (count == 0)
                maxlen = max(maxlen, i + 1);
            if (mpp.find(count) != mpp.end())
                maxlen = max(maxlen, i - (mpp[count] + 1) + 1);
            else {
                mpp[count] = i;
            }
        }
        return maxlen;
    }
};