class Solution {
public:
    
    double myPow(double x, long long n) 
    {
        double ans = 1, h = 1;
        if(n<0){
            h = -1;
            n=-n;
        }
        while(n>0)
        {
            if(n&1)
                ans*=x;
            n = (n>>1);
            if(n<=0) break;
            x*=x;
        }
        if(h==-1)
            return 1/ans;
        return ans;
    }
};