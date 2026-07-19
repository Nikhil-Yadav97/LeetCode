class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 1);
        vector<int> count(n + 1, 1);
        int maxlen=1;
        for (int ind = 0; ind < n; ind++) {
            for (int prev = 0; prev < ind; prev++) {
                if (nums[prev] < nums[ind]) {
                    if(1+dp[prev]>dp[ind]){
                        dp[ind]=1+dp[prev];
                        count[ind]=count[prev];
                    }else{
                    if(1+dp[prev]==dp[ind]){
                        count[ind]+=count[prev];
                    }
                    }
                }
            }
            maxlen=max(maxlen,dp[ind]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxlen)
            ans+=count[i];
        }
        return ans;
    }
};