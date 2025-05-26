class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &it: times)
            adj[it[0]].push_back({it[1],it[2]});
        // for(int i = 0; i<n+1; i++)
        // {
        //     cout<<i<<endl;
        //     for(int j = 0; j<adj[i].size(); j++)
        //         cout<<adj[i][j].first<<" "<<adj[i][j].second<<endl;
        // }
        vector<int> dist(n+1,1e9);
        dist[k] = 0;
        set<pair<int,int>> q;
        q.insert({0,k});
        while(!q.empty())
        {
            auto it = *q.begin();
            q.erase(it);
            int node = it.second;
            int d = it.first;
            for(auto &x: adj[node])
            {
                int newNode = x.first;
                int len = x.second;
                if(dist[newNode]>len+d)
                {
                    dist[newNode] = len+d;
                    q.insert({dist[newNode],newNode});
                }
            }
        }
        int x = 0;
        for(int i = 1; i<n+1; i++)
        {
            if(dist[i]==1e9)
                return -1;
            x = max(x,dist[i]);
        }
        return x;
    }
};