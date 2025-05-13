class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) 
    {
        int n = mat.size(), m = mat[0].size(), ma = 0, h = 0;
        for(int i = 0; i<n; i++)
        {
            int count = 0;
            for(int j = 0; j<m; j++)
            {
                if(mat[i][j]==1)
                    count++;
            }
            if(count>ma)
            {
                ma = count;
                h = i;
            }
        }
        return {h,ma};
    }
};