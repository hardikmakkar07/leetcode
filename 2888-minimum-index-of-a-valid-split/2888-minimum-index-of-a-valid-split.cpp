class Solution {
public:
    int minimumIndex(vector<int>& nums) 
    {
        int n = nums.size();
        map<int,int>mp;
        for(int x: nums)
        {
            mp[x]++;
        }
        int ma = 0, x;
        for(auto &it: mp)
        {
            if(it.second>ma)
            {
                x = it.first;
                ma = it.second;
            }
        }
        int ans = -1, count = 0;
        for(int i = 0; i<n; i++)
        {
            if(nums[i]==x)
                count++;
            if(count>(i+1)/2 && (ma-count)*2>(n-i-1))
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};