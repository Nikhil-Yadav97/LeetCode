class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1,maxlen=1,dec=1;
        if(nums.size()==0)
        return 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1]){
                inc++;
                dec=1;
            }
            else{
                if(nums[i]<nums[i-1])
                {
                    dec++;
                    inc=1;
                }
                else{
                    dec=1;
                    inc=1;
                }
            }
            maxlen=max(maxlen,max(inc,dec));
        }
        return maxlen;
    }
};