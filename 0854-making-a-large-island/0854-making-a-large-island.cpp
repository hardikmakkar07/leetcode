class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i<=n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if(rank[ulp_v]<rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution 
{
public:
    bool isValid(int adjr, int adjc, int n, int m) {
        return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        DisjointSet ds(n*m);

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int row = 0; row<n; row++)
        {
            for(int col = 0; col<m; col++)
            {
                if(grid[row][col]==1)
                {
                    for(int ind = 0; ind < 4; ind++) 
                    {
                        int adjr = row + dr[ind];
                        int adjc = col + dc[ind];
                        if(isValid(adjr,adjc,n,m) && grid[adjr][adjc]==1) 
                        {
                            int nodeNo = row * m + col;
                            int adjNodeNo = adjr * m + adjc;
                            ds.unionBySize(nodeNo,adjNodeNo);
                        }
                    }
                }
            }
        }
        int ans = 0;
        bool h = false;
        for(int row = 0; row<n; row++)
        {
            for(int col = 0; col<m; col++)
            {
                set<int> uniquePar;
                if(grid[row][col]==0)
                {
                    h = true;
                    for(int ind = 0; ind < 4; ind++) 
                    {
                        int adjr = row + dr[ind];
                        int adjc = col + dc[ind];
                        if(isValid(adjr,adjc,n,m) && grid[adjr][adjc]==1) 
                        {
                            int nodeNo = row * m + col;
                            int adjNodeNo = adjr * m + adjc;
                            uniquePar.insert(ds.findUPar(adjNodeNo));
                        }
                    }
                }
                int mx = 0;
                for(auto it: uniquePar)
                {
                    mx+=ds.size[it];
                }
                ans = max(ans,mx);
            }
        }
        if(!h) return n*m;
        return ans+1;
    }
};