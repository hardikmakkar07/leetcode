class Solution {
public:
    void answer(int ind, int n, vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, vector<bool> &pick)
    {
        if(ind==n)
        {
            ans.push_back(ds);
            return;
        }
        for(int i = 0; i<n; i++)
        {
            if(!pick[i])
            {
                ds.push_back(nums[i]);
                pick[i] = true;
                answer(ind+1,n,ds,nums,ans,pick);
                ds.pop_back();
                pick[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> ds;
        vector<bool> pick(n,false);
        answer(0,n,ds,nums,ans,pick);
        return ans;
    }
};