class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) 
    {
        map<int,int>mp;
        
        for(auto x:nums)
        {
            mp[x]++;
        }
        
        // for(auto x:mp)
        // {
        //     if(mp.find(original)!=mp.end())
        //     {
        //         original =2 *original;
        //     }
        // }
        
        while(mp.find(original)!=mp.end())
        {
            original =original *2;
        }
        return original;
        
    }
};
