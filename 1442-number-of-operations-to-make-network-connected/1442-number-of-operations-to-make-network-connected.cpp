class DisjointSet
{
    vector<int> parent, rank;
public:
    DisjointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i = 0; i<=n; i++)
            parent[i] = i;
    }

    int findUPar(int node)
    {
        if(parent[node]==node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if(rank[ulp_u] > rank[ulp_v])
            parent[ulp_v] = ulp_u;
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        int x = connections.size();
        if(x<n-1)
            return -1;
        DisjointSet ds(n);
        for(int i = 0; i<x; i++)
        {
            int u = connections[i][0], v = connections[i][1];
            if(ds.findUPar(u)!=ds.findUPar(v))
            {
                ds.unionByRank(u,v);
            }
        }
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            if(ds.findUPar(i)==i)
                count++;
        }
        return count-1;
    }
};