class Solution {
public:
    int numberOfArrays(vector<int>& d, int lower, int upper) 
    {
        long long mi = 0, ma = 0, c = 0;
        for(int i = 0; i<d.size(); i++)
        {
            c+=d[i];
            if(c<mi)
                mi = c;
            if(c>ma)
                ma = c;
        }
        int x = (upper-lower)-(ma-mi)+1;
        return max(0,x);
    }
};