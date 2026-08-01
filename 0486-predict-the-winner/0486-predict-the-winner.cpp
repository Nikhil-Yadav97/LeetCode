class Solution {
public:

    int fn(vector<int> &nums,int i,int j)
    {
        if(i>j)
        return 0;

        int takei=nums[i]+min(fn(nums,i+2,j),fn(nums,i+1,j-1));
        int takej=nums[j]+min(fn(nums,i,j-2),fn(nums,i+1,j-1));
        return max(takei,takej);
    }
    bool predictTheWinner(vector<int>& nums) {
        int sum=accumulate(begin(nums),end(nums),0);
        int player1=fn(nums,0,nums.size()-1);
        return player1>=(sum-player1);
    }
};