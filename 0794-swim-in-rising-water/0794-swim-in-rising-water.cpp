class Solution {
public:
    bool isValid(int adjr, int adjc, int n, int m) {
        return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
    }
    
    int swimInWater(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int l = 0, r = n*n-1;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<bool> vis(n*n,false);
        pq.push({grid[0][0],{0,0}});
        int dr[] = { -1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        vis[grid[0][0]] = true;
        while(!pq.empty())
        {
            int maxEle = pq.top().first;
            int row = pq.top().second.first, col = pq.top().second.second;
            pq.pop();
            
            if(row==n-1 && col==n-1)
                return maxEle;
            for(int ind = 0; ind < 4; ind++) 
            {
                int adjr = row+dr[ind];
                int adjc = col+dc[ind];
                if(isValid(adjr,adjc,n,n) && !vis[grid[adjr][adjc]])
                {
                    int ma = max(maxEle,grid[adjr][adjc]);
                    vis[grid[adjr][adjc]] = true;
                    pq.push({ma,{adjr,adjc}});
                }
            }
        }
        return n*n-1;
    }
};