class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        
        int n = grid.size();
        pq.push({grid[0][0], 0, 0});
        vector<vector<int>> vis(n, vector<int>(n, 1e8));
        vis[0][0] = grid[0][0];
        int nrow[] = {-1, 0, 1, 0};
        int ncol[] = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto [dis, r, c] = pq.top();
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int row = nrow[i] + r;
                int col = ncol[i] + c;

                if (row >= 0 && col >= 0 && col < n && row < n) {
                    if (vis[row][col] > max(grid[row][col], vis[r][c])) {
                        vis[row][col] = max(grid[row][col], vis[r][c]);
                        pq.push({vis[row][col], row, col});
                    }
                }
            }
        }
            return vis[n - 1][n - 1];
    }
};