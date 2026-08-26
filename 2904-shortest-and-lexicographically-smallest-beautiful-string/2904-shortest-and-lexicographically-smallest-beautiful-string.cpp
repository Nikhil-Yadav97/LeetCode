class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
         int l = 0, r = 0, n = s.size();
        int onecount = 0;
        while (r < n) {
            if (s[r] == '1')
                onecount++;

            while (onecount > k) {
                if (s[l] == '1')
                    onecount--;
                l++;
            }

            while (l <= r && onecount == k && s[l] == '0') {
                l++;
            }

            if (onecount == k) {
                string window = s.substr(l, r - l + 1);
                if (ans.size() == 0 || ans.size() > window.size() ||
                    (ans.size() == window.size() && ans > window))
                    ans = window;
            }
            r++;
        }
        return ans;
    }
};