#define ll long long

class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        bool isNegative = false;
        if((dividend<0 && divisor>0) ||(dividend>0 && divisor<0)) isNegative = true;
        ll x = abs((long long)divisor);
        ll y = abs((long long)dividend);
        ll ans = 0;
        while(y>=x)
        {
            ll h = 0;
            for(ll i = 0; ; i++)
            {
                if((x<<i)>y)
                {
                    h = i-1;
                    // cout<<h<<endl;
                    break;
                }
            }
            y-=(x<<h);
            ans+=(1ll<<h);
        }
        // cout<<ans<<endl;
        if(ans>=INT_MAX && !isNegative) return INT_MAX;
        if(ans==INT_MAX && isNegative) return -INT_MAX;
        if(ans>INT_MAX && isNegative) return INT_MIN;
        if(isNegative) ans*=-1;
        return (int)ans;
    }
};