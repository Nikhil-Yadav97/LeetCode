class Solution {
public:
    int minMoves(vector<int>& nums) {
        int value=*max_element(nums.begin(),nums.end());
        int moves=0;
        for(auto it : nums)
            {
                moves+=value-it;
            }
        return moves;
    }
};