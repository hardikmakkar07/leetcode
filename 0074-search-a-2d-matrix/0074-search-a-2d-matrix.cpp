class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n-1, h=-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(matrix[mid][0]==target)
                return true;
            else if(matrix[mid][0]<target)
            {
                h = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        if(h==-1) return false;
        l = 0; r = m-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(matrix[h][mid]==target)
                return true;
            else if(matrix[h][mid]<target)
                l = mid+1;
            else
                r = mid-1;
        }
        return false;
    }
};