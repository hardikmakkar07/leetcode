class Solution {
public:
    void bfs(vector<vector<int>> &adj, vector<int> &indegree, queue<int> &q, int &count)
    {
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            count++;
            for(int y: adj[x])
            {
                indegree[y]--;
                if(!indegree[y])
                    q.push(y);
            }
        }
    }
    bool canFinish(int n, vector<vector<int>>& pre) 
    {
        vector<vector<int>> adj(n,vector<int>());
        for(int i = 0; i<pre.size(); i++)
        {
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        vector<int> indegree(n,0);
        for(auto it: adj)
        {
            for(auto x: it)
                indegree[x]++;
        }
        queue<int> q;
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            if(!indegree[i])
            {
                q.push(i);
            }
        }
        bfs(adj,indegree,q,count);
        return count==n;   
    }
};