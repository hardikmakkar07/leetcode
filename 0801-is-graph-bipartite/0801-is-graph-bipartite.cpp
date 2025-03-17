class Solution {
public:
    bool colour(int i,vector<vector<int>> &graph, vector<int> &vis)
    {
        queue<int> q;
        q.push(i);
        vis[i] = 0;
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            for(int i = 0; i<graph[x].size(); i++)
            {
                if(vis[graph[x][i]]==-1)
                {
                    vis[graph[x][i]] = !vis[x];
                    q.push(graph[x][i]);
                }
                else if(vis[graph[x][i]]==vis[x])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> vis(n,-1);
        for(int i = 0; i<n; i++)
        {
            if(vis[i]==-1)
            {
                if(!colour(i,graph,vis))
                    return false;
            }
        }
        return true;
    }
};