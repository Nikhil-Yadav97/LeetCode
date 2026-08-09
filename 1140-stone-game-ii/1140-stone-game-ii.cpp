class Solution {
public:
    int dp[101][101][2];

    int fn(vector<int>& piles, int ind, int chance, int M) {
        if (ind >= piles.size())
            return 0;

        if (dp[ind][M][chance] != -1)
            return dp[ind][M][chance];

        int result = chance ? INT_MIN : INT_MAX;
        int sum = 0;

        for (int i = 1; i <= min((int)piles.size() - ind, 2 * M); i++) {

            sum += piles[ind + i - 1];

            if (chance) {
                result = max(result,
                    sum + fn(piles, ind + i, !chance, max(M, i)));
            }
            else {
                result = min(result,
                    fn(piles, ind + i, !chance, max(M, i)));
            }
        }

        return dp[ind][M][chance] = result;
    }

    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return fn(piles, 0, 1, 1);
    }
};