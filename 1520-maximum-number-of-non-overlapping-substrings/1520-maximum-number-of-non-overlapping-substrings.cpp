class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<bool> valid(n, true);
        vector<int> start(27, -1), last(27, -1), maxlen(n, -1);

        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (start[idx] == -1)
                start[idx] = i;

            last[idx] = i;
        }

        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if(start[idx]!=i)
            continue;
            int lastindx = last[idx];

            maxlen[i] = lastindx;
            for (int ind = i; ind <= lastindx; ind++) {
                int ch = s[ind] - 'a';
                if (start[ch] < i) {
                    valid[i] = false;
                    break;
                }
                lastindx = max(lastindx, last[ch]);
            }
            maxlen[i] = lastindx;
        }
        vector<string> ans;
        int lastused=n;
        for (int i = n - 1; i >= 0; i--) {
            if (valid[i] && maxlen[i]!=-1 &&maxlen[i]<lastused) {
                int len = maxlen[i] - i + 1;
                ans.push_back(s.substr(i, len));
                lastused=i;
            }
        }

        return ans;
    }
};