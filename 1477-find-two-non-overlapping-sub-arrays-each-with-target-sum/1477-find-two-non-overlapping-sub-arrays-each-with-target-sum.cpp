class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int l = 0, r = 0, sum = 0;
        int n = arr.size();
        vector<int> minuntilthis(n, INT_MAX);
        int ans = INT_MAX, bestmin = INT_MAX;
        while (r < arr.size()) {
            sum += arr[r];
            while (sum > target) {
                sum -= arr[l];
                l++;
            }
            if (sum == target) {
                if (l > 0 && minuntilthis[l - 1] != INT_MAX)
                    ans = min(ans, r - l + 1 + minuntilthis[l - 1]);
                bestmin = min(bestmin, r-l + 1);
            }
            minuntilthis[r] = bestmin;
            r++;
        }
        return ans != INT_MAX ? ans : -1;
    }
};