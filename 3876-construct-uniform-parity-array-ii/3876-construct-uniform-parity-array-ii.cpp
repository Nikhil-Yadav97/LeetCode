class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(begin(nums1),end(nums1));
        int n=nums1.size();
        if(nums1[0]%2==0)
        {
            bool odd=false;
            for(auto it : nums1)
            {
                if(it%2)
                return false;
            }
        }
        return true;
        
    }
};