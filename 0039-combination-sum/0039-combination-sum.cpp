class Solution {
public:
    void answer(int ind, int sum, vector<int> &candidates, int target, vector<int> &temp, vector<vector<int>> &ans)
    {
        if(sum>target || ind>=candidates.size())
            return;
        if(sum==target)
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(candidates[ind]);
        answer(ind,sum+candidates[ind],candidates,target,temp,ans);
        temp.pop_back();
        answer(ind+1,sum,candidates,target,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        answer(0,0,candidates,target,temp,ans);
        return ans;
    }
};