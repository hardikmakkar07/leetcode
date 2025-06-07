class Solution {
public:
    bool isValid(int adjr, int adjc, int n, int m) {
        return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
    }
    bool check(vector<vector<int>> &grid, int mid, int n)
    {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        if(grid[0][0]<=mid)
        {
            pq.push({grid[0][0],{0,0}});
            vis[0][0] = true;
        }
        int dr[] = { -1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while(!pq.empty())
        {
            int maxEle = pq.top().first;
            int row = pq.top().second.first, col = pq.top().second.second;
            pq.pop();
            
            if(row==n-1 && col==n-1)
                return true;
            for(int ind = 0; ind < 4; ind++) 
            {
                int adjr = row+dr[ind];
                int adjc = col+dc[ind];
                if(isValid(adjr,adjc,n,n) && grid[adjr][adjc]<=mid && !vis[adjr][adjc])
                {
                    int ma = max(maxEle,grid[adjr][adjc]);
                    vis[adjr][adjc] = true;
                    pq.push({ma,{adjr,adjc}});
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int l = 0, r = n*n-1;

        int ans = r;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(check(grid,mid,n))
            {
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return ans;
    }
};