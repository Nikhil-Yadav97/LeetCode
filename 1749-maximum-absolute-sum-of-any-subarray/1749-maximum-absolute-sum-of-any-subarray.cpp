class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size(),sum=nums[0],maxsum=nums[0];
        for(int i=1;i<n;i++)
        {
            sum=max(sum+nums[i],nums[i]);
            maxsum=max(maxsum,sum);
        }
        sum=nums[0];
        int minsum=nums[0];
        for(int i=1;i<n;i++)
        {
            sum=min(sum+nums[i],nums[i]);
            minsum=min(minsum,sum);
        }
        return max(abs(minsum),abs(maxsum));
    }
};