class Solution {
public:
    bool check(vector<int>& weights, int mid, int days) {
        int capacity = 0;
        int day = 1;
        for (auto wt : weights) {
            if (capacity + wt > mid) {
                day++;
                capacity = 0;
            }
            capacity += wt;
        }
        return day <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for (auto wt : weights) {
            high += wt;
        }
        int ans ;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(weights, mid, days)) {
                ans = mid;
                high = mid - 1;

            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};