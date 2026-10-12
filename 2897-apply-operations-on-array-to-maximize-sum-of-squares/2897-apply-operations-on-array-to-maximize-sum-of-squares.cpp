class Solution {
public:
    int mod = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> count(32, 0);
        for (auto num : nums) {
            for (int i = 0; i < 32; i++) {
                if (num & (1 << i))
                    count[i]++;
            }
        }

        long long result = 0;
        while (k--) {
            long long number = 0;
            for (int i = 31; i >= 0; i--) {
                if (count[i]) {
                    number = number | (1 << i);
                    count[i]--;
                }
            }
            result = (result + (number % mod * number % mod) % mod) % mod;
        }
        return result;
    }
};