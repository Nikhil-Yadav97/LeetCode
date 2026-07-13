class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<tuple<int, int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans(mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int nrow[] = {-1, 0, 1, 0};
        int ncol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto [i, j, dis] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int row = i + nrow[k];
                int col = j + ncol[k];
                if (row < n && col < m && col >= 0 && row >= 0 &&
                        !vis[row][col] && mat[row][col] == 1) {
                    vis[row][col] = 1;
                    q.push({row, col, dis + 1});
                    ans[row][col]=dis+1;
                }
            }
        }
        return ans;
    }
};