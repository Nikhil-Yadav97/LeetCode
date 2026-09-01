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

        vector<vector<int>> litterno(n, vector<int>(m, -1));

        // Find start and number litter
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                if (classroom[i][j] == 'L') {
                    litterno[i][j] = littercount++;
                }
            }
        }

        int totalMasks = 1 << littercount;
        int reqmask = totalMasks - 1;

        /*
            maxEnergy[x][y][mask]

            Maximum energy with which we have reached
            (x, y) after collecting 'mask' litter.
        */
        vector<vector<vector<int>>> maxEnergy(
            n,
            vector<vector<int>>(
                m,
                vector<int>(totalMasks, -1)
            )
        );

        queue<state> q;

        q.push({sx, sy, energy, 0});
        maxEnergy[sx][sy][0] = energy;

        int nrow[] = {-1, 0, 1, 0};
        int ncol[] = {0, 1, 0, -1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [row, col, ene, mask] = q.front();
                q.pop();

                if (mask == reqmask)
                    return moves;

                if (ene == 0)
                    continue;

                for (int i = 0; i < 4; i++) {

                    int r = row + nrow[i];
                    int c = col + ncol[i];

                    // Boundary
                    if (r < 0 || r >= n || c < 0 || c >= m)
                        continue;

                    // Wall
                    if (classroom[r][c] == 'X')
                        continue;

                    // One move consumes one energy
                    int newEnergy = ene - 1;

                    int newMask = mask;

                    // Collect litter
                    if (classroom[r][c] == 'L') {

                        int lno = litterno[r][c];

                        newMask |= (1 << lno);
                    }

                    // Recharge
                    if (classroom[r][c] == 'R') {
                        newEnergy = energy;
                    }

                    /*
                        If we have already reached this
                        (r, c, newMask) with >= energy,
                        this state is useless.
                    */
                    if (maxEnergy[r][c][newMask] >= newEnergy)
                        continue;

                    maxEnergy[r][c][newMask] = newEnergy;

                    q.push({
                        r,
                        c,
                        newEnergy,
                        newMask
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};