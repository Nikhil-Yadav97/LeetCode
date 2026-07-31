class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
       int maxlen=1;
       map<int,int> mpp;
       int n=nums.size(),l=0,r=0;
       while(r<n)
       {
        mpp[nums[r]]++;
        while(mpp[nums[r]]>k)
        {
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0)
            mpp.erase(nums[l]);
            l++;
        }
        maxlen=max(maxlen,r-l+1);
        r++;

       }
       return maxlen; 
    }
};