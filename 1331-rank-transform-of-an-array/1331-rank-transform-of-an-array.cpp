class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0)
        return {};
        vector<pair<int, int>> nums;
        for (int i = 0; i < arr.size(); i++) {
            nums.push_back({arr[i], i});
        }
        sort(begin(nums), end(nums));
        int rank = 1, last = nums[0].first;
        arr[nums[0].second] = 1;
        for (int i = 1; i < nums.size(); i++) {
            auto it = nums[i];
            if (last != it.first) {
                rank++;
                arr[it.second] = rank;
            } else {
                arr[it.second] = rank;
            }
            last = it.first;
        }
        return arr;
    }
};