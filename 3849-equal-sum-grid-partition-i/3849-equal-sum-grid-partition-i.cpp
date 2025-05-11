class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();

        vector<long long> row(n,0), col(m,0);
        for(int i = 0; i<n; i++)
        {
            long long sum = 0;
            for(int j = 0; j<m; j++)
            {
                sum+=grid[i][j];
            }
            if(i==0)
                row[i] = sum;
            else
                row[i] = row[i-1]+sum;
        }
        long long tot = row[n-1];
        for(int j = 0; j<m; j++)
        {
            long long sum = 0;
            for(int i = 0; i<n; i++)
            {
                sum+=grid[i][j];
            }
            if(j==0)
                col[j] = sum;
            else
                col[j] = col[j-1]+sum;
        }
        for(int i = 0; i<n; i++)
        {
            if(row[i]==tot-row[i])
                return true;
        }
        for(int j = 0; j<m; j++)
        {
            if(col[j]==tot-col[j])
                return true;
        }
        return false;
    }
};