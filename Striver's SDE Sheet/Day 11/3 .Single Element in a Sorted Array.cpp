class Solution {
public:
    // using hashmap 
    // tc: o(n)
    // sc: o(n)
    int singleNonDuplicate(vector<int>& nums) 
    {
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto x:mp)
        {
            if(x.second==1)
            {
                ans= x.first;
            }
        }
        return ans;
    }
    
    // using bit manipulation concept 
    // tc:o(n)
    // sc:o(1)
    int singleNonDuplicate(vector<int>& nums) 
    {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans =ans^ nums[i];
        }
        return ans;
    }
    
//     using most optimised approach 
//     Binary Search 
//     tc: o(logn)
//     sc:o(1)
     int singleNonDuplicate(vector<int>& nums) 
     {
         int low=0;
         int high =nums.size()-2;
         while(low<=high)
         {
             int mid = (low+high)/2;
             if(mid%2==0)
             {
                 if(nums[mid]!=nums[mid+1])
                 {
                     high=mid-1;
                 }
                 else
                 {
                     low=mid+1;
                 }
             }
             else
             {
                 if(nums[mid]==nums[mid+1])
                 {
                     high=mid-1;
                 }
                 else
                 {
                     low=mid+1;
                 }
             }
         }
         return nums[low];
     }
    
    // using most optimised approach 
    // Binary Search +XOR concept 
    // tc: o(logn)
    // sc:o(1) 
    // odd xor 1 = even 
     int singleNonDuplicate(vector<int>& nums) 
     {
         int low=0;
         int high =nums.size()-2;
         while(low<=high)
         {
             int mid =low +(high-low)/2;
             if(nums[mid]==nums[mid^1])
             {
                 low=mid+1;
             }
             else
             {
                 high=mid-1;
             }
         }
         return nums[low];
     }
};
