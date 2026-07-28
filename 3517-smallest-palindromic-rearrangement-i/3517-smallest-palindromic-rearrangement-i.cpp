class Solution {
public:
    string smallestPalindrome(string s) {
        int i = 0,  n = s.size();
        int half=n/2;
        sort(begin(s), begin(s)+half);
        for(int i=0;i<half;i++)
        {
            s[n-1-i]=s[i];
        }
        return s;
    }
};