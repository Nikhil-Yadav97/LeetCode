class Solution {
public:
    string shortestCommonSupersequence(string t1, string t2) {
        int n = t1.size(), m = t2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int ind1 = n - 1; ind1 >= 0; ind1--) {
            for (int ind2 = m - 1; ind2 >= 0; ind2--) {
                if (t1[ind1] == t2[ind2])
                    dp[ind1][ind2] = 1 + dp[ind1 + 1][ind2 + 1];

                dp[ind1][ind2] = max(
                    {dp[ind1][ind2], dp[ind1 + 1][ind2], dp[ind1][ind2 + 1]});
            }
        }
        int i=0,j=0;
        string ans="";
        while(i<n && j<m){
            if(t1[i]==t2[j]){
                ans+=t1[i];
                i++;
                j++;
            }else{
                if(dp[i][j+1]<=dp[i+1][j])
                {
                    ans+=t1[i];
                    i++;
                }else{
                    ans+=t2[j];
                    j++;
                }
            }
        }
        while(i<n){
            ans+=t1[i++];
        }
        while(j<m){
            ans+=t2[j++];
        }
        return ans;
    }
};