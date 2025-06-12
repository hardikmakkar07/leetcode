class Solution {
public:
    void solve(int ind, int sum, vector<int> &curr, vector<vector<int>> &ans, int k, int n)
    {
        if(curr.size()==k)
        {
            if(sum==n)
                ans.push_back(curr);
            return;
        }
        for(int i = ind; i<=9; i++)
        {
            curr.push_back(i);
            solve(i+1,sum+i,curr,ans,k,n);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(1,0,curr,ans,k,n);
        return ans;
    }
};