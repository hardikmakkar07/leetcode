class Solution {
public:
    
    bool a[50000001];
    void sieve(int n)
    {
        fill(a,a+n+1,true);
        a[0] = a[1] = false;
        for(int i = 2; i*i<=n; i++)
        {
            for(int j=i*i; j<=n; j+=i)
                a[j] = false;
        }
    }
    int countPrimes(int n) 
    {
        sieve(n);
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            if(a[i])
                count++;
        }
        return count;
    }
};