class Solution {
public:
    void fn(int ind, string& num, int target, vector<string>& ans, string str,
            long long preval, long long res) {
        if (ind == num.size()) {
            if (target == res)
                ans.push_back(str);
            return;
        }

        long long currval = 0;
        for (int i = ind; i < num.size(); i++) {
            int digit = num[i] - '0';
            currval = currval * 10 + digit;

            if (i > ind && num[ind] == '0')
                break;
            if (ind == 0) {
                fn(i + 1, num, target, ans, to_string(currval), currval,
                   res + currval);
                
            } else {
                fn(i + 1, num, target, ans, str + "+" + to_string(currval),
                   currval, res + currval);
                fn(i + 1, num, target, ans, str + "-" + to_string(currval),
                   -currval, res - currval);
                fn(i + 1, num, target, ans, str + "*" + to_string(currval),
                   preval * currval, (res - preval) + preval * currval);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        fn(0, num, target, ans, "", 0, 0);
        return ans;
    }
};