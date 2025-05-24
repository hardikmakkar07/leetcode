class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int n = heights.size(), m = heights[0].size();

        set<pair<int,pair<int,int>>> st;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        st.insert({0,{0,0}});
        dist[0][0] = 0;
        while(!st.empty())
        {
            auto it = *st.begin();
            int x = it.second.first, y = it.second.second, dif = it.first;
            st.erase(it);
            if(dist[x][y]<dif) continue;
            if(x==n-1 && y==m-1) return dif;
            if(x>0 && max(abs(heights[x-1][y]-heights[x][y]),dif)<dist[x-1][y])
            {
                dist[x-1][y] = max(abs(heights[x-1][y]-heights[x][y]),dif);
                st.insert({dist[x-1][y],{x-1,y}});
            }
            if(y>0 && max(abs(heights[x][y-1]-heights[x][y]),dif)<dist[x][y-1])
            {
                dist[x][y-1] = max(abs(heights[x][y-1]-heights[x][y]),dif);
                st.insert({dist[x][y-1],{x,y-1}});
            }
            if(x<n-1 && max(abs(heights[x+1][y]-heights[x][y]),dif)<dist[x+1][y])
            {
                dist[x+1][y] = max(abs(heights[x+1][y]-heights[x][y]),dif);
                st.insert({dist[x+1][y],{x+1,y}});
            }
            if(y<m-1 && max(abs(heights[x][y+1]-heights[x][y]),dif)<dist[x][y+1])
            {
                dist[x][y+1] = max(abs(heights[x][y+1]-heights[x][y]),dif);
                st.insert({dist[x][y+1],{x,y+1}});
            }
        }
        return dist[n-1][m-1];
    }
};