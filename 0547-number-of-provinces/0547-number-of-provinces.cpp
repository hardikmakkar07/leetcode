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
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        DisjointSet ds(n);
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(i!=j && isConnected[i][j] && ds.findUPar(i)!=ds.findUPar(j))
                {
                    ds.unionByRank(i,j);
                }
            }
        }
        set<int>st;
        for(int i = 0; i<n; i++)
        {
            st.insert(ds.findUPar(i));
        }
        return st.size();
    }
};