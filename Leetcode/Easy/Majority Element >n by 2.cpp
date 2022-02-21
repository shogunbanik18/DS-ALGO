class Solution {
public:
    // using Hashing 
    // tc:o(n)
    // sc:o(n)
    int majorityElement(vector<int>& nums)
    {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        int ans=0;
        for(auto x:mp)
        {
            if(x.second>n/2)
            {
                ans=x.first;
            }
        }
        return ans;
    }
    
    // using Moore's voting algorithm 
    // tc:o(n)
    // sc:o(1)
    int majorityElement(vector<int>& nums)
    {
        int n=nums.size();
        int count=0;
        int ele=0;
        for(auto x:nums)
        {
            if(count==0)
            {
                ele=x;
            }
            
            if(x==ele)
            {
                count++;
            }
            else if(x!=ele)
            {
                count--;
            }
        }
        return ele;
    }
};
