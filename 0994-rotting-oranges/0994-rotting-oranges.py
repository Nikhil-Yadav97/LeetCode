from collections import deque
class Solution:
    def orangesRotting(self, grid: list[list[int]]) -> int:
        n, m = len(grid), len(grid[0])
        fresh = 0
        q = deque()
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    fresh += 1
                if grid[i][j] == 2:
                    q.append((i, j, 0))

        nrow = [-1, 0, 1, 0]
        ncol = [0, 1, 0, -1]
        tm=0
        if fresh==0:
            return 0
        while q:
            i, j, time = q.popleft()
            tm=max(time,tm)
            

            for dir in range(4):
                row=i+nrow[dir]
                col=j+ncol[dir]

                if row>=0 and col>=0 and col<m and row<n :
                    if grid[row][col]==1:
                        grid[row][col]=2
                        q.append((row,col,time+1))
                        fresh-=1
        if fresh==0:
            return tm
        return -1