class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> mpp;
        vector<int> used(26, false);
        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]] = i;
        }
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(used[ch-'a'])
            continue;
            while (!st.empty() && st.top() >= ch && mpp[st.top()] > i) {
                used[st.top() - 'a'] = false;
                st.pop();
            }
            
                st.push(ch);
                used[ch - 'a'] = true;
            
        }
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};