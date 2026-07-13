class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        queue<tuple<string, int>> q;
        q.push({beginWord, 1});
        map<string, int> mpp;
        for (auto& it : wordList) {
            mpp[it]++;
        }
        while (!q.empty()) {
            auto [str, cnt] = q.front();
            if (str == endWord)
                return cnt;
            q.pop();

            for (int i = 0; i < str.size(); i++) {
                int chr = str[i];
                for (auto ch = 'a'; ch <= 'z'; ch++) {
                    str[i] = ch;
                    if (mpp.find(str) != mpp.end()) {
                        q.push({str, cnt + 1});
                        mpp.erase(str);
                    }
                }
                str[i] = chr;
            }
        }
        return 0;
    }
};