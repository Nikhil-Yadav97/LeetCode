class Solution {
public:
    long long fn(vector<vector<int>>& intervals, int ind) {
        int n = intervals.size();
        int l = ind + 1, r = n - 1;
        int index=-1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (intervals[mid][0] <= intervals[ind][1] &&
                    intervals[mid][1] >= intervals[ind][1] ||
                intervals[mid][1] >= intervals[ind][0] &&
                    intervals[mid][1] <= intervals[ind][1]) {
                index = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (index==-1)
        return 0 ;
        return index-ind;
    }
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        long long count = 0;
        sort(begin(intervals), end(intervals));
        for (int i = 0; i < n; i++) {
            count += fn(intervals, i);
        }
        return count;
    }
};