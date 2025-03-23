class Solution {
public:
    long long power(long long a, long long b) 
    {
        long long ans = 1;
        while (b > 0) {
            if (b & 1)
                ans *= a;
            b = (b >> 1);
            if (b <= 0)
                break;
            a *= a;
        }
        return ans;
    }
    long long ans(long long l, long long r) 
    {
        long long sum = 0;
        for (long long i = 1; i < 32; i++) 
        {
            long long mi = power(4,i-1);
            long long ma = power(4,i)-1;
            if(mi<=r && ma>=l)
            {
                long long a = max(mi,l);
                long long b = min(ma,r);
                sum+= i*(b-a+1);
            }
        }
        return sum;
    }
    long long minOperations(vector<vector<int>>& queries) {
        int n = queries.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (ans(queries[i][0], queries[i][1]) + 1) / 2;
        }
        return sum;
    }
};