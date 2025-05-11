class Solution {
public:
    int minDeletion(string s, int k) 
    {
        vector<int> v(26,0);
        for(auto it: s)
        {
            v[it-'a']++;
        }
        int count = 0;
        for(int i = 0; i<v.size(); i++)
        {
            if(v[i]==0)
            {
                v[i]=INT_MAX;
                count++;
            }
        }
        int num = 26-count;
        sort(v.begin(),v.end());
        int ans = 0;
        for(int i = 0; i<num-k; i++)
        {
            ans+=v[i];
        }
        return ans;
    }
};