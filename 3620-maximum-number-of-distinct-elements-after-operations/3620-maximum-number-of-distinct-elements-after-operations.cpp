class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());

        for(int i = 0; i<nums.size(); i++)
        {
            if(i==0)
            {
                nums[i] = nums[i]-k;
            }
            else
            {
                int t = nums[i-1]+1;
                if(abs(nums[i]-t)<=k)
                    nums[i] = t;
                else if(nums[i]-t>k)
                    nums[i]-=k;
                else
                    nums[i]+=k;
            }
        }
        for(int i = 0; i<nums.size(); i++)
        {
            cout<<nums[i]<<" ";
        } cout<<endl;
        set<int> a(nums.begin(),nums.end());
        return (int)a.size();
    }
};