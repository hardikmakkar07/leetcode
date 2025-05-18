class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) 
    {
        int n = mat.size(), m = mat[0].size();
        int l = 0, r = m-1;
        while(l<=r)
        {
            int mid = l+(r-l)/2, maxi=INT_MIN, h;
            for(int i = 0; i<n; i++)
            {
                if(mat[i][mid]>maxi)
                {
                    maxi = mat[i][mid];
                    h = i;
                }
            }
            int left=-1, right=-1;
            if(mid>=1)
                left = mat[h][mid-1];
            if(mid<m-1)
                right = mat[h][mid+1];
            if(mat[h][mid]>left && mat[h][mid]>right)
                return {h,mid};
            else if(mat[h][mid]<left)
                r = mid-1;
            else
                l = mid+1;
        }
        return {-1,-1};
    }
};