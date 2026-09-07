class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<long long> prev(m, 0);
        for (int i = 0; i < m; i++) {
            prev[i] = points[0][i];
        }

        for (int j = 1; j < n; j++) {
            vector<long long> left(m, 0);
            left[0] = prev[0];
            for (int i = 1; i < m; i++) {
                left[i] = max(prev[i], left[i - 1] - 1);
            }
            vector<long long> right(m, 0);
            right[m - 1] = prev[m - 1];
            for (int i = m - 2; i >= 0; i--) {
                right[i] = max(prev[i], right[i + 1] - 1);
            }

            vector<long long> curr(m, 0);
            for (int i = 0; i < m; i++) {
                curr[i] = max(left[i], right[i]) + points[j][i];
            }
            prev = curr;
        }
        return *max_element(begin(prev), end(prev));
    }
};