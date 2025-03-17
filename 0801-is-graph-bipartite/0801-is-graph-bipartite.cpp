class Solution {
public:
    bool colour(int i,vector<vector<int>> &graph, vector<int> &vis)
    {
        queue<int> q;
        q.push(i);
        int col = 1;
        while(!q.empty())
        {
            int h = q.size();
            for(int i = 0; i<h; i++)
            {
                int x = q.front();
                q.pop();
                if(!vis[x])
                    vis[x] = col;
                else if(vis[x]!=col)
                    return false;
                for(int j = 0; j<graph[x].size();  j++)
                {
                    if(!vis[graph[x][j]])
                        q.push(graph[x][j]);
                }
            }
            if(col==1)
                col = 2;
            else
                col = 1;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> vis(n,0);
        for(int i = 0; i<n; i++)
        {
            if(!vis[i])
            {
                if(!colour(i,graph,vis))
                    return false;
            }
        }
        return true;
    }
};