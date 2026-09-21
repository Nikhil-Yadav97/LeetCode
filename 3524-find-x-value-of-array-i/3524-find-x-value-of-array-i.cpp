class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k, 0), prev(k + 1, 0);
        for (int i = 0; i < n; i++) {
            vector<long long> curr(k + 1, 0);
            long long rem = nums[i] % k;
            curr[rem] = 1;
            for (int oldrem = 0; oldrem < k; oldrem++) {
                int newrem = ((long long)oldrem * nums[i]) % k;
                curr[newrem] += prev[oldrem];
            }
            prev = move(curr);
            for (int j = 0; j <= k-1; j++)
                result[j] += prev[j];
        }
        return result;
    }
};