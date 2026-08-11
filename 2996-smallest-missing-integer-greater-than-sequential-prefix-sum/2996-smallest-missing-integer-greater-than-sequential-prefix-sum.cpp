class Solution {
public:
    int missingInteger(vector<int>& nums) {
        set<int> st(begin(nums),end(nums));
        int n=nums.size();
        int sum=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1]+1)
            sum+=nums[i];
            else
            break;
        }
        while(st.count(sum))
        {
            if(st.find(sum)!=st.end())
            sum++;
        }
        return sum;
    }
};