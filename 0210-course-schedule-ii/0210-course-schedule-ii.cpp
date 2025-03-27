class Solution {
public:
    void bfs(vector<vector<int>> &adj, vector<int> &indegree, queue<int> &q, int &count, vector<int> &ans)
    {
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            count++;
            for(int y: adj[x])
            {
                indegree[y]--;
                if(!indegree[y])
                    q.push(y);
            }
        }
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) 
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
        vector<int> ans;
        bfs(adj,indegree,q,count,ans);
        if(count!=n)
            return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};