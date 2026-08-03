class Solution {
public:
    void fn(vector<int> &nums,int ind,vector<vector<int>> &ans){
        int n=nums.size();
        if(ind>=n){
            ans.push_back(nums);
            return ;

        }

        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[i],nums[ind]);
            fn(nums,ind+1,ans);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> ans;
      fn(nums,0,ans);
      return ans;  
    }
};