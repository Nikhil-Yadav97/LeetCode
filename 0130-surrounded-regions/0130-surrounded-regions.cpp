class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<tuple<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X')
                    vis[i][j] = 1;
                if (board[i][j] == 'O' &&
                    (i == 0 || j == 0 || i == n - 1 || j == m - 1)) {
                    q.push({i, j});
                    vis[i][j]=2;
                }
            }
        }
        int nrow[]={-1,0,1,0};
        int ncol[]={0,1,0,-1};
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int row = nrow[k] + i;
                int col = ncol[k] + j;
                if (row >= 0 && col >= 0 && col < m && row < n &&
                    vis[row][col] == 0 && board[row][col] == 'O') {
                    vis[row][col] = 2;
                    q.push({row, col});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0)
                    board[i][j] = 'X';
            }
        }
    }
};