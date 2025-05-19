class Solution {
public:
    bool pallindrome(string &s, int i, int j)
    {
        int l = i, r = j;
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    string longestPalindrome(string s) 
    {
        int h, k, ma = 0, n = s.size();
        for(int i = 0; i<n; i++)
        {
            for(int j = i; j<n; j++)
            {
                if((j-i+1)>ma && pallindrome(s,i,j))
                {
                    ma = j-i+1;
                    h = j;
                    k = i;
                }
            }
        }
        string ans;
        for(int i = k; i<=h; i++)
            ans.push_back(s[i]);
        return ans;
    }
};