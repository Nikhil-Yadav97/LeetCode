class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> path(n, vector<int>(m, 0));
        if (grid[0][0] == 1)
            return 0;

        path[0][0]=1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    continue;
                int up = (i - 1) >= 0 ? path[i - 1][j] : 0;
                int left = (j - 1) >= 0 ? path[i][j - 1] : 0;
                path[i][j] += up + left;
            }
        }
        return path[n - 1][m - 1];
    }
};