class Solution {
public:
    int nrow[2] = {1, 0};
    int ncol[2] = {0, 1};

    int dp[105][105][205];

    bool fn(vector<vector<char>>& grid, int i, int j, int val) {
        int n = grid.size();
        int m = grid[0].size();

        val += (grid[i][j] == ')') ? -1 : 1;

        if (val < 0)
            return false;

        int remaining = (n - 1 - i) + (m - 1 - j);

        if (val > remaining)
            return false;

        if (i == n - 1 && j == m - 1) {

            return dp[i][j][val] = (val == 0);
        }

        if (dp[i][j][val] != -1)
            return dp[i][j][val];

        for (int dir = 0; dir < 2; dir++) {
            int r = i + nrow[dir];
            int c = j + ncol[dir];

            if (r >= n || c >= m)
                continue;

            

            if (fn(grid, r, c, val))
                return dp[i][j][val] = true;
        }

        return dp[i][j][val] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if ((n + m - 1) % 2 != 0)
            return false;

        if (grid[0][0] == ')' || grid[n - 1][m - 1] == '(')
            return false;

        memset(dp, -1, sizeof(dp));

        return fn(grid, 0, 0, 0);
    }
};