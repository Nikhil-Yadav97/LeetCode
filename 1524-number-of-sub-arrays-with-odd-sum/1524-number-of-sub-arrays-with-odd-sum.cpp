class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size(), count = 0;
        vector<pair<int, int>> prefix;
        int mod = 1e9 + 7;
        prefix.push_back((arr[0] % 2) ? make_pair(0, 1) : make_pair(1, 0));
        count += (arr[0] % 2) ? 1 : 0;
        for (int i = 1; i < n; i++) {
            auto [even, odd] = prefix.back();
            if (arr[i] % 2) {
                prefix.push_back({odd, 1 + even});
            } else {
                prefix.push_back({even + 1, odd});
            }
            count = (count + prefix.back().second) % mod;
        }

        return count;
    }
};