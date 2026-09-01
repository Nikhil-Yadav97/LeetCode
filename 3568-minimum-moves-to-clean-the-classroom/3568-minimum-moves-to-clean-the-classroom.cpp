struct state {
    int x;
    int y;
    int e;
    int mask;
};

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int n = classroom.size();
        int m = classroom[0].size();

        int sx, sy;
        int littercount = 0;

        vector<vector<int>> litterno(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                if (classroom[i][j] == 'L') {
                    littercount++;
                    litterno[i][j] = littercount;
                }
            }
        }

        int totalMasks = 1 << littercount;
        int reqmask = totalMasks - 1;

        // vis[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> vis(
            n,
            vector<vector<vector<bool>>>(
                m,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(totalMasks, false)
                )
            )
        );

        queue<state> q;

        q.push({sx, sy, energy, 0});
        vis[sx][sy][energy][0] = true;

        int nrow[] = {-1, 0, 1, 0};
        int ncol[] = {0, 1, 0, -1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [row, col, ene, msk] = q.front();
                q.pop();

                if (msk == reqmask)
                    return moves;

                if (ene == 0)
                    continue;

                for (int i = 0; i < 4; i++) {

                    int r = row + nrow[i];
                    int c = col + ncol[i];

                    if (r < 0 || r >= n || c < 0 || c >= m)
                        continue;

                    if (classroom[r][c] == 'X')
                        continue;

                    int newene = ene - 1;
                    int newmask = msk;

                    // Recharge
                    if (classroom[r][c] == 'R') {
                        newene = energy;
                    }

                    // Litter
                    if (classroom[r][c] == 'L') {
                        int lno = litterno[r][c];
                        newmask |= 1 << (lno - 1);
                    }

                    if (!vis[r][c][newene][newmask]) {

                        vis[r][c][newene][newmask] = true;

                        q.push({
                            r,
                            c,
                            newene,
                            newmask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};