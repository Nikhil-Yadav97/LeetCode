class Solution {
public:
    int minInsertions(string s) {
        int n = s.size(), count = 0;
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                st.push('(');
            else {
                if (s[i] == ')') {
                    if (!st.empty()) {
                        st.pop();
                        if (i + 1 >= n || s[i + 1] != ')') {
                            count++;
                        } else {
                            i++;
                        }

                    } else {
                        count++;
                        if (i + 1 >= n || s[i + 1] != ')') {
                            count++;
                        } else {
                            i++;
                        }
                    }
                }
            }
        }
        while (!st.empty()) {
            count += 2;
            st.pop();
        }
        return count;
    }
};