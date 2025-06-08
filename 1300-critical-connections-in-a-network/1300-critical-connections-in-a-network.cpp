class Solution 
{

    int timer = 0;
public:
    void dfs(int node, int parent, vector<vector<int>> &graph, vector<int> &tin, vector<int> &low, vector<bool> &vis, vector<vector<int>> &ans)
    {
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it: graph[node])
        {
            if(it==parent) continue;
            if(!vis[it])
            {
                dfs(it,node,graph,tin,low,vis,ans);
                low[node] = min(low[it],low[node]);
                if(low[it]>=tin[node]+1)
                    ans.push_back({it,node});
            }
            else
                low[node] = min(low[it],low[node]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        vector<vector<int>> graph(n,vector<int>());
        for(int i = 0; i<connections.size(); i++)
        {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        vector<vector<int>> ans;
        vector<int> tin(n), low(n);
        vector<bool> vis(n,false);
        dfs(0,-1,graph,tin,low,vis,ans);
        return ans;
    }
};