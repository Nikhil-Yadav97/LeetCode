class Solution {
public:
    vector<vector<int>> dp;
    int fn(vector<vector<int>> &costs,int ind,int n,int a,int b)
    {
        if(n==a && n==b && ind>=costs.size())
        return 0;
        if(ind>=costs.size())
        return 1e8;

        if(dp[a][b]!=-1)
        return dp[a][b];

        int costa=costs[ind][0]+fn(costs,ind+1,n,a+1,b);
        int costb=costs[ind][1]+fn(costs,ind+1,n,a,b+1);
        return dp[a][b]= min(costa,costb);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size()/2;
        dp.resize(2*n+1,vector<int> (2*n+1,-1));
        return fn(costs,0,n,0,0);
    }
};