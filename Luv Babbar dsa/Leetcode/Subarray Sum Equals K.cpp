class Solution {
public:
    // brute force
    // wont work here 
    // tc:o(n*n)
    // sc:o(1)
    int subarraySum(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]+nums[i-1]==k)
            {
                count++;
            }
        }
        return count;
    }
    
     // using the concept of hashing and prefix sum 
    // tc:o(n)
    // sc:o(n)
     int subarraySum(vector<int>& nums, int k) 
     {
         unordered_map<int,int>mp;
         int count=0,sum=0;
         int n=nums.size();
         for(int i=0;i<n;i++)
         {
             sum+=nums[i];
             if(sum==k)
             {
                 count++;
             }
             
             if(mp.find(sum-k)!=mp.end())
             {
                 count+=mp[sum-k];
             }
             
             if(mp.find(sum)!=mp.end())
             {
                  mp[sum]++;
             }
             else
             {
                 mp[sum]=1;
             }
         }
         return count;  
     }
};
