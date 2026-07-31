class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
    int maxlen=1;
    int n=nums.size(),l=0,r=0;
    long long sum=0;
    sort(begin(nums),end(nums));
    while(r<n)
    {
        sum+=nums[r];
        while(((long long)(r-l+1)*nums[r]-sum)>k)
        {
            sum-=nums[l];
            l++;
        }
        maxlen=max(maxlen,r-l+1);
        r++;
    }
    return maxlen;    
    }
};