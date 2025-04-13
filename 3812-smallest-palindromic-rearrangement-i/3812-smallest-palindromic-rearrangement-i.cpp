class Solution {
public:
    string smallestPalindrome(string s) 
    {
        map<char,int> mp;
        for(auto it: s)
        {
            mp[it]++;
        }
        bool h = false;
        string x;
        char m;
        for(auto it: mp)
        {
            if(it.second%2==1)
            {
                h = true;
                m = it.first;
            }
            for(int i = 0; i<it.second/2; i++)
            {
                x.push_back(it.first);
            }
        }
        cout<<x<<endl;
        string y;
        y = x;
        reverse(x.begin(),x.end());
        if(h)
            y.push_back(m);
        y+=x;
        return y;
    }
};