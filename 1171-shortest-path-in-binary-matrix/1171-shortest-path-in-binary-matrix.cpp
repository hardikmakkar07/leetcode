class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();

        vector<vector<bool>> vis(n,vector<bool>(n,false));
        queue<vector<int>> q;
        if(grid[0][0]==0)
        {
            q.push({0,0,1});
            vis[0][0] = true;
        }
        int ans = 1e9;
        while(!q.empty())
        {
            int x = q.front()[0];
            int y = q.front()[1];
            int d = q.front()[2];
            q.pop();
            if(x==n-1 && y==n-1)
                return d;
            if(x<n-1 && grid[x+1][y]==0 && !vis[x+1][y])
            {
                q.push({x+1,y,d+1});
                vis[x+1][y] = true;
            }
            if(y<n-1 && grid[x][y+1]==0 && !vis[x][y+1])
            {
                q.push({x,y+1,d+1});
                vis[x][y+1] = true;
            }
            if(x<n-1 && y<n-1 && grid[x+1][y+1]==0 && !vis[x+1][y+1])
            {
                q.push({x+1,y+1,d+1});
                vis[x+1][y+1] = true;
            }
            if(x>0 && grid[x-1][y]==0 && !vis[x-1][y])
            {
                q.push({x-1,y,d+1});
                vis[x-1][y] = true;
            }
            if(y>0 && grid[x][y-1]==0 && !vis[x][y-1])
            {
                q.push({x,y-1,d+1});
                vis[x][y-1] = true;
            }
            if(x<n-1 && y>0 && grid[x+1][y-1]==0 && !vis[x+1][y-1])
            {
                q.push({x+1,y-1,d+1});
                vis[x+1][y-1] = true;
            }
            if(x>0 && y<n-1 && grid[x-1][y+1]==0 && !vis[x-1][y+1])
            {
                q.push({x-1,y+1,d+1});
                vis[x-1][y+1] = true;
            }
            if(x>0 && y>0 && grid[x-1][y-1]==0 && !vis[x-1][y-1])
            {
                q.push({x-1,y-1,d+1});
                vis[x-1][y-1] = true;
            }
        }
        return -1;
    }
};