class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int d = 0, n = seq.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                d++;
                if (d % 2 == 0) {
                    ans.push_back(0);
                } else {
                    ans.push_back(1);
                }
            } else {
                if (d % 2 == 0) {
                    ans.push_back(0);
                } else {
                    ans.push_back(1);
                }
                d--;
            }
        }
        return ans;
    }
};