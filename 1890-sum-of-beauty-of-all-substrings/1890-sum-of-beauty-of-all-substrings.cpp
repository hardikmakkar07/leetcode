class Solution {
public:
    int beautySum(string s) 
    {
        int n = s.size(), ans = 0;
        for(int i = 0; i<n; i++)
        {
            vector<int> mp(26,0);
            for(int j = i; j<n; j++)
            {
                mp[s[j]-'a']++;
                int mini = INT_MAX, maxi = INT_MIN;
                for(int k = 0; k<26; k++)
                {
                    if(mp[k]!=0)
                    {
                        if(mp[k]>maxi)
                            maxi = mp[k];
                        if(mp[k]<mini)
                            mini = mp[k];
                    }
                }
                if(mini>0)
                    ans+=(maxi-mini);
            }
        }
        return ans;
    }
};