class Solution {
public:
    bool isPallindrome(int start, int end, string s)
    {
        while(start<end)
        {
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    void answer(int ind, int n, vector<vector<string>> &ans, string &s, vector<string> &temp)
    {
        if(ind==n)
        {
            ans.push_back(temp);
            return;
        }

        for(int i = ind; i<n; i++)
        {
            if(isPallindrome(ind,i,s))
            {
                string x = s.substr(ind,i-ind+1);
                temp.push_back(x);
                answer(i+1,n,ans,s,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> temp;
        answer(0,n,ans,s,temp);
        return ans;
    }
};