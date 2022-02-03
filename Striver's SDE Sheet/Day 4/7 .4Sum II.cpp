class Solution {
public:
    // using brute force 
    // tc:o(n^4)
    // sc:o(1)
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        int count=0;
        for(auto i:nums1)
        {
            for(auto j:nums2)
            {
                for(auto k:nums3)
                {
                    for(auto l:nums4)
                    {
                        if(i+j+k+l==0)
                        {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
    
    // using better approach 
    // tc:o(n^3)
    // sc:o(1)
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        int count=0;
        unordered_map<int,int>mp;
        for(auto l:nums4)
        {
            mp[l]++;
        }
        for(auto i:nums1)
        {
            for(auto j:nums2)
            {
                for(auto k:nums3)
                {
                    int target=0-(i+j+k);
                    if(mp.find(target)!=mp.end())
                    {
                        count=count+mp[target];
                    }
                }
            }
        }
        return count;
    }
    
    // using better approach 
    // tc:o(n^2)
    // sc:o(1)
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        int count=0;
        unordered_map<int,int>mp;
        int n=nums1.size();
        for(auto k :nums3)
        {
            for(auto l:nums4)
            {
                mp[k+l]++;
            }
        }
       for(auto i:nums1)
       {
           for(auto j:nums2)
           {
               int target=0-(i+j);
               if(mp.find(target)!=mp.end())
               {
                   count+=mp[target];
               }
           }
       }
        return count;
    }
};
