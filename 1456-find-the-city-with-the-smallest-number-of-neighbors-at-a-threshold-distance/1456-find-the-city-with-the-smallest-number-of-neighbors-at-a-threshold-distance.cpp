class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) 
    {
        vector<vector<int>> dist(n,vector<int>(n,0));
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(i!=j)
                    dist[i][j] = 1e9;
            }
        }
        for(int i = 0; i<edges.size(); i++)
        {
            dist[edges[i][0]][edges[i][1]] =  edges[i][2];
            dist[edges[i][1]][edges[i][0]] =  edges[i][2];  
        }
        for(int k = 0; k<n; k++)
        {
            for(int i = 0; i<n; i++)
            {
                for(int j = 0; j<n; j++)
                {
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int ans=1e9, city;
        for(int i = 0; i<n; i++)
        {
            int ma = 0;
            for(int j = 0; j<n; j++)
            {
                if(dist[i][j]<=d)
                    ma++;
            }
            if(ma<=ans)
            {
                ans = ma;
                city = i;
            }
        }
        return city;
    }
};