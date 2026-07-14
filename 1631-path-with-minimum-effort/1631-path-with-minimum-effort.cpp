class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 1e8));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        pq.push({0, 0, 0});
        vis[0][0] = 0;
        int nrow[] = {-1, 0, 1, 0};
        int ncol[] = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto [dis, i, j] = pq.top();
            pq.pop();

            for (int k = 0; k < 4; k++) {
                int row = nrow[k] + i;
                int col = ncol[k] + j;

                if (row >= 0 && col >= 0 && col < m && row < n) {
                    int neweffort =
                        max(abs(heights[row][col] - heights[i][j]), vis[i][j]);
                    if (neweffort < vis[row][col]) {
                        vis[row][col] = neweffort;
                        pq.push({neweffort, row, col});
                    }
                }
            }
        }
        return vis[n - 1][m - 1];
    }
};