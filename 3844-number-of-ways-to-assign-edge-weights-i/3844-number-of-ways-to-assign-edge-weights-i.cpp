class Solution {
public:
    long long power(long long a, long long b)
{
    long long ans = 1;
    while(b > 0)
    {
        if(b & 1)
            ans = (ans*a)%((long long)1e9+7);
        b = (b >> 1);
        if(b <= 0)
            break;
        a = (a*a)%((long long)1e9+7);
    }
    return ans%((long long) 1e9+7);
}
    int assignEdgeWeights(vector<vector<int>>& edges) 
    {
        int n = 0;
        for(int i = 0; i<edges.size(); i++)
            {
                        n = max(n,max(edges[i][0],edges[i][1]));
            }
        vector<vector<int>> adj(n+1,vector<int>());
        for(int i = 0; i<edges.size(); i++)
            {
                adj[edges[i][0]].push_back(edges[i][1]);
                adj[edges[i][1]].push_back(edges[i][0]);
            }
        queue<int> q;
        q.push(1);
        int count = 0;
        for(int i = 0; i<adj[1].size(); i++)
            cout<<adj[1][i]<<" ";
        cout<<endl;
        vector<bool> vis(n+1, false);
        vis[1] = true;
        while(!q.empty())
            {
                int h = q.size();
                for(int i = 0; i<h; i++)
                    {
                        int x = q.front();
                        q.pop();
                        cout<<x<<endl;
                        if(adj[x].size()>0)
                        {
                            for(int j = 0; j<adj[x].size(); j++)
                                {
                                    if(!vis[adj[x][j]])
                                    {
                                        q.push(adj[x][j]);
                                        vis[adj[x][j]]= true;
                                    }
                                }
                        }
                    }
                count++;
            }
        cout<<count<<endl;
            int ans = power(2,count-2);
        return ans;
    }
};