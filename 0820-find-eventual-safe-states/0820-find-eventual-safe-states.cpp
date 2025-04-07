class Solution 
{
public:
    bool dfs(int i, vector<bool> &vis, vector<bool> &pathVis, vector<vector<int>> &graph)
    {
        vis[i] = true;
        pathVis[i] = true;
        for(int j = 0; j<graph[i].size(); j++)
        {
            if(!vis[graph[i][j]])
            {
                if(dfs(graph[i][j],vis,pathVis,graph))
                    return true;
            }
            else if(pathVis[graph[i][j]])
                return true;
        }
        pathVis[i] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<bool> vis(n,false), pathVis(n,false);

        for(int i = 0; i<n; i++)
        {
            if(!vis[i])
                dfs(i,vis,pathVis,graph);
        }
        vector<int> ans;
        for(int i = 0; i<n; i++)
        {
            if(!pathVis[i])
                ans.push_back(i);
        }
        return ans;
    }
};