class Solution {
public:
    int findTheLongestSubstring(string s) {

        map<int, int> mpp;
        mpp[0] = -1;
        int count = 0;
        int maxlen = 0;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == 'a')
                count = count ^ (1 << 1);
            if (ch == 'e')
                count = count ^ (1 << 2);
            if (ch == 'i')
                count = count ^ (1 << 3);
            if (ch == 'o')
                count = count ^ (1 << 4);
            if (ch == 'u')
                count = count ^ (1 << 5);

            

            if (mpp.find(count) != mpp.end())
                maxlen = max(maxlen, i - mpp[count]);
            else
                mpp[count] = i;
        }
        return maxlen;
    }
};