class Solution {
public:
#define MOD 1000000007
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        vector<vector<pair<long long, long long>>> adj(n);
        for(auto &it: roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> st;
        vector<long long> dist(n,1e18);
        dist[0] = 0;
        vector<long long> ways(n);
        ways[0] = 1;
        st.push({0,0});
        while(!st.empty())
        {
            auto it =st.top();
            long long d = it.first, node = it.second;
            st.pop();
            for(auto &x: adj[node])
            {
                long long newNode = x.first;
                long long len = x.second;
                if(dist[newNode]>(d+len))
                {
                    dist[newNode] = d+len;
                    st.push({dist[newNode],newNode});
                    ways[newNode] = ways[node]%MOD;
                }
                else if(dist[newNode]==(d+len))
                {
                    ways[newNode]=((ways[newNode]%MOD)+(ways[node]%MOD))%MOD;
                }
            }
        }
        return ways[n-1]%MOD;
    }
};