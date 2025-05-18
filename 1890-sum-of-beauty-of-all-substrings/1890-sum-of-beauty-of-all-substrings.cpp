class Solution {
public:
    int beautySum(string s) 
    {
        int n = s.size(), ans = 0;
        for(int i = 0; i<n; i++)
        {
            map<char,int> mp;
            for(int j = i; j<n; j++)
            {
                mp[s[j]]++;
                if(mp.size()>1)
                {
                    int mini = INT_MAX, maxi = INT_MIN;
                    for(auto it: mp)
                    {
                        if(it.second>maxi)
                            maxi = it.second;
                        if(it.second<mini)
                            mini = it.second;
                    }
                    ans+=(maxi-mini);
                }
            }
        }
        return ans;
    }
};