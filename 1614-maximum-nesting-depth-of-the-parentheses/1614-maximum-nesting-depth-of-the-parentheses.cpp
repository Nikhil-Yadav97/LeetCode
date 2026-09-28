class Solution {
public:
    int maxDepth(string s) {
        int maxdepth = 0,depth=0;
        for (auto ch : s) {
            if (ch == '(') {
                depth++;
            }
            if (ch == ')') {
                depth--;
            }
            maxdepth = max(depth, maxdepth);
        }
        return maxdepth;
    }
};