class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long ans=0;
        for(auto it : nums){
            pq.push(it);
        }
        while(k--)
        {
            int value=pq.top();
            pq.pop();
            pq.push(ceil(value/3.0));
            ans+=value;
        }
        return ans;
    }
};