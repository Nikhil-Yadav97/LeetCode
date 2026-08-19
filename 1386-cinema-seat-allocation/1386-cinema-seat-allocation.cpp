class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, int> mpp;
        for (auto& it : reservedSeats) {
            auto row=it[0];
            auto seat=it[1];
            mpp[row] = mpp[row] | (1 << seat);
        }
        int count = 0;
        count = (n - mpp.size()) * 2;
        int groupA = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int groupB = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int groupC = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);
        for (auto& [row, mask] : mpp) {
            bool grpA = (groupA & mask) == 0;
            bool grpB = (groupB & mask) == 0;
            bool grpC = (groupC & mask) == 0;

            if (grpA && grpC)
                count += 2;
            else {
                if (grpA || grpB || grpC)
                    count++;
            }
        }
        return count;
    }
};