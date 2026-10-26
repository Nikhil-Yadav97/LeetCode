class Solution {
    public:
    void cal(vector<vector<int>>& grid,vector<vector<int>>& vis, int i,int j,int &count,int k)
    {
        long long value=0;
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        value+=grid[i][j];
        int nrow[]={-1,0,1,0};
        int ncol[]={0,1,0,-1};
        while(!q.empty())
            {
                i=q.front().first;
                j=q.front().second;
                q.pop();

                for(int k=0;k<4;k++)
                    {
                        int row=i+nrow[k];
                        int col=j+ncol[k];
                        if(row>=0 && col>=0 && col<grid[0].size() && row<grid.size() && vis[row][col]!=1 && grid[row][col]!=0)
                        {
                            vis[row][col]=1;
                            value+=grid[row][col];
                            q.push({row,col});
                        }
                    }
                
            }
        if(value%k==0)
            count++;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int count=0;
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                    {
                        if(grid[i][j]!=0 && vis[i][j]==0)
                           cal(grid,vis,i,j,count,k);
                    }
            }
        return count;
        
    }
};