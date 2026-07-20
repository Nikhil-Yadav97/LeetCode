class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        int total=n*m;
        k=k%total;
        vector<vector<int>> ans(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int idx=i*m+j;
                int newindex=(idx+k)%(n*m);
                
                int r=newindex/m,c=newindex%m;
                ans[r][c]=grid[i][j];
            }
        }
        return ans;
    }
};