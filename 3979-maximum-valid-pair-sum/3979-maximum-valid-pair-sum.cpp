class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> maxele(n,0);
        maxele[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxele[i]=max(maxele[i+1],nums[i]);
        }
        int ans=nums[0];
        for(int i=0;i<n;i++)
        {
            if(i+k<n)
            {
                ans=max(ans,maxele[i+k]+nums[i]);
            }
        }
        return ans;
    }
};