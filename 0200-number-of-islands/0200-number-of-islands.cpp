class Solution {
public:
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j,int n, int m)
    {
        vis[i][j] = true;
        if(i>0 && !vis[i-1][j] && grid[i-1][j]=='1')
            dfs(grid,vis,i-1,j,n,m);
        if(j>0 && !vis[i][j-1] && grid[i][j-1]=='1')
            dfs(grid,vis,i,j-1,n,m);
        if(i<n-1 && !vis[i+1][j] && grid[i+1][j]=='1')
            dfs(grid,vis,i+1,j,n,m);
        if(j<m-1 && !vis[i][j+1] && grid[i][j+1]=='1')
            dfs(grid,vis,i,j+1,n,m);
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m));
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    dfs(grid,vis,i,j,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};