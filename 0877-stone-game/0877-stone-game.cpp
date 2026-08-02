class Solution {
public:
    int fn(vector<int>& piles, int i, int j, vector<vector<int>> &dp) {
        if (i > j)
            return 0;
        if (i == j)
            return piles[i];

        if(dp[i][j]!=-1)
        return dp[i][j];

        int take = min(fn(piles, i + 2, j,dp), fn(piles, i + 1, j - 1,dp)) + piles[i];
        int nottake =
            min(fn(piles, i + 1, j - 1,dp), fn(piles, i, j - 2,dp)) + piles[j];

        return dp[i][j]=max(take, nottake);
    }
    bool stoneGame(vector<int>& piles) {
        int sum = accumulate(begin(piles), end(piles), 0);
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        int player1 = fn(piles, 0, n - 1,dp);
        return (player1 > (sum - player1));
    }
};