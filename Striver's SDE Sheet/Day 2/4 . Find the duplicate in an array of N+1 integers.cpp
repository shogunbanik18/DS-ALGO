// use of hashing 
class Solution {
public:  
    // brute force naive approach
    // tc :O(NlogN)
    // sc:O(N)
    int findDuplicate(vector<int>& nums)
    {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                ans= nums[i];
            }
        }
        return ans;
    }
       
    // tc :O(N)
    // sc:O(N)
    int findDuplicate(vector<int>& nums)
    {
         int ans=0;
        int n=nums.size();
         unordered_map<int,int>mp;
         for(int i=0;i<n;i++)
         {
             mp[nums[i]]++;
         }
         for(auto x:mp)
         {
             if(x.second>1)
             {
                  ans=x.first; 
             }
         }
         return ans;
    }
    
    // using hare tortoise method 
    // floyds algorithm of cycle detction in linked list 
    // tc :O(N)
    // sc:O(1)
    int findDuplicate(vector<int>& nums)
    {  
        int slow=nums[0];
        int fast=nums[0];
        do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
            
        fast=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};



