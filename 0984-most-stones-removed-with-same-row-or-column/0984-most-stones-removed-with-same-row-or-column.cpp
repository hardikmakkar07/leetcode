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
    int removeStones(vector<vector<int>>& stones) 
    {
        map<int,vector<int>> x, y;
        int n = stones.size();
        DisjointSet ds(n);
        for(int i = 0; i<n; i++)
        {
            x[stones[i][0]].push_back(i);
            y[stones[i][1]].push_back(i);
        }
        for(auto &it: x)
        {
            for(int i = 1; i<it.second.size(); i++)
            {
                ds.unionByRank(it.second[i],it.second[i-1]);
            }
        }
        for(auto &it: y)
        {
            for(int i = 1; i<it.second.size(); i++)
            {
                ds.unionByRank(it.second[i],it.second[i-1]);
            }
        }
        // for(auto &it: y)
        // {
        //     for(int i = 1; i<it.size(); i++)
        //     {
        //         ds.unionByRank(it[i],it[i-1]);
        //     }
        // }
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            if(ds.findUPar(i)==i)
                count++;
        }
        return n-count;
    }
};