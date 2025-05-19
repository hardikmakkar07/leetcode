class Solution {
public:
    pair<int,int> calc(string &s, int l, int r)
    {
        int n = s.size();
        while(l>=0 && r<=n-1 && s[l]==s[r])
        {
            l--;
            r++;
        }
        return {l+1,r-1};
    }
    string longestPalindrome(string s) 
    {
        int n = s.size();
        if(n==1)
            return s;
        int ans = 0;
        int l, r;
        string a;
        for(int i = 0; i<n-1; i++)
        {
            pair<int,int> odd = calc(s,i,i);
            pair<int,int> even = calc(s,i,i+1);
            if(odd.second-odd.first+1>ans)
            {
                l = odd.first;
                r = odd.second;
                ans = r-l+1;
            }
            if(even.second-even.first+1>ans)
            {
                l = even.first;
                r = even.second;
                ans = r-l+1;
            }
        }
        for(int i = l; i<=r; i++)
            a.push_back(s[i]);
        return a;
    }
};