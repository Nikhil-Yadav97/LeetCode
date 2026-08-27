class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int freq[26] = {0};
        for (auto ch : s) {
            freq[ch - 'a']++;
        }

        bool greater = false;
        int i = 0, n = target.size();
        string ans = "";
        while (i < n) {
            char ch = target[i];
            if (freq[ch - 'a']) {
                ans += ch;
                freq[ch - 'a']--;
                i++;
            } else {
                for (char chr = target[i] + 1; chr <= 'z'; chr++) {
                    if (freq[chr - 'a']) {
                        greater = true;
                        freq[chr - 'a']--;
                        ans += chr;
                        break;
                    }
                }
                
                    break;
                
            }
        }

        while (i>0 && greater == false) {
            char ch = ans.back();
            ans.pop_back();
            i--;
            freq[ch - 'a']++;
            for (char chr = target[i] + 1; chr <= 'z'; chr++) {
                if (freq[chr - 'a']>0) {
                    greater = true;
                    ans += chr;
                    freq[chr - 'a']--;
                    break;
                }
            }
        }

        if (!greater)
            return "";

        for (char ch = 'a'; ch <= 'z'; ch++) {
            while (freq[ch - 'a'] > 0) {
                ans += ch;
                freq[ch - 'a']--;
            }
        }
        return ans;
    }
};