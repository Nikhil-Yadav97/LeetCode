class Solution {
public:
    bool check(vector<int>&nums,int mid,int k){
        int sum=0;
        k--;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>mid){
                k--;
                sum=0;
            }
            sum+=nums[i];
        }
        return k>=0;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(begin(nums),end(nums));
        int high=accumulate(begin(nums),end(nums),0);
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(nums,mid,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};