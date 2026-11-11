class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        if(need1>need2)
        return minimumCost(cost2,cost1,costBoth,need2,need1);

        long long both=min(costBoth,cost1+cost2);
        long long cost=need1*both;
        cost+=(need2-need1)*(long long)(min(costBoth,cost2));
        return cost;
        
    }
};