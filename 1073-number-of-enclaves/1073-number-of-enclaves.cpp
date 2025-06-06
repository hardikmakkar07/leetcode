class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<int>> &grid)
    {
        if(i==-1||j==-1||i==n||j==m)
            return;
        if(grid[i][j])
        {
            grid[i][j]=0;
            dfs(i+1,j,n,m,grid);
            dfs(i,j+1,n,m,grid);
            dfs(i,j-1,n,m,grid);
            dfs(i-1,j,n,m,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if((i==0 || i==n-1 || j==0 || j==m-1) && (grid[i][j]==1))
                {
                    dfs(i,j,n,m,grid);
                }
            }
        }
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(grid[i][j]==1)
                    count++;
            }
        }
        return count;
    }
};