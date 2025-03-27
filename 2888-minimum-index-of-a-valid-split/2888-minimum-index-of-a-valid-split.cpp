class Solution {
public:
    int minimumIndex(vector<int>& nums) 
    {
        int n = nums.size();
        int freq = 0, x;
        for(int i = 0; i<n; i++)
        {
            if(freq==0)
            {
                x = nums[i];
                freq++;
            }
            else if(nums[i]==x)
                freq++;
            else if(nums[i]!=x)
                freq--;
        }

        int ma = 0;
        for(int i = 0; i<n; i++)
        {
            if(nums[i]==x)
                ma++;
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