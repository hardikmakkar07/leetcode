class Solution 
{
public:
    // bool dfs(int i, vector<bool> &vis, vector<bool> &pathVis, vector<vector<int>> &graph)
    // {
        
    // }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<vector<int>> adj(n,vector<int>());
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<graph[i].size(); j++)
            {
                adj[graph[i][j]].push_back(i);
            }
        }
        vector<int> indegree(n,0);
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<adj[i].size(); j++)
            {
                indegree[adj[i][j]]++;
            }
        }
        queue<int> q;
        for(int i = 0; i<n; i++)
        {
            if(!indegree[i])
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            int x = q.front();
            ans.push_back(x);
            q.pop();
            for(int j = 0; j<adj[x].size(); j++)
            {
                indegree[adj[x][j]]--;
                if(indegree[adj[x][j]]==0)
                    q.push(adj[x][j]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};