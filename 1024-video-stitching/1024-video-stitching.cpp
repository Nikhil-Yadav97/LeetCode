class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(begin(clips), end(clips));
        int count = 0;
        int i = 0, n = clips.size();
        if (clips[0][0] != 0)
            return -1;
        int last = 0;
        int farthest = last;
        while (last < time) {
            while (i < n && last >= clips[i][0]) {
                farthest = max(farthest, clips[i][1]);
                i++;
            }
            if (farthest == last)
                return -1;

            count++;
            last = farthest;
        }
        return last >= time ? count : -1;
    }
};