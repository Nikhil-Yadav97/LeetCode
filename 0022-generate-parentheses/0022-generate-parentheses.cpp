class Solution {
public:
    void fn(int ind, int n, string& str, int left, int right,
            vector<string>& ans) {
        if (left + right == 0 && ind == 2 * n) {
            ans.push_back(str);
            return;
        }
        if (ind >= 2 * n)
            return;

        if(left+right<0)
        return ;
        str += '(';
        fn(ind + 1, n, str, left+1, right, ans);
        str.pop_back();
        str += ')';

        fn(ind + 1, n, str, left, right-1, ans);
        str.pop_back();
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        fn(0, n, str, 0, 0, ans);
        return ans;
    }
};