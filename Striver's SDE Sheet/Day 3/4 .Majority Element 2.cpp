class Solution {
public:
//     Brute force 
//    tc:O(n^2)
//   Doesnot work for test case  [2,2]
    vector<int> majorityElement(vector<int>& nums)
    {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int count=1;
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]==nums[i])
                {
                    count++;
                }
            }
            if(count>n/3)
                {
                    ans.push_back(nums[i]);
                }
        }
        return ans;
    }
  
    // using hashmap 
    // floor off n/3 
    // tc:o(n) or o(nlogn)
    // sc:o(n) for the vector v
    vector<int> majorityElement(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>v;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto x:mp)
        {
            if(x.second>n/3)
            {
                v.push_back(x.first);
            }
        }
        return v;
    }
    
    // tc:O(N)
    // sc:O(1)
    // Boyer Moore's Voting Algorithm 
     vector<int> majorityElement(vector<int>& nums)
     {
         int n=nums.size();
         int num1=-1,num2=-1,count1=0,count2=0,i;
         for(i=0;i<n;i++)
         {
             if(nums[i]==num1)
             {
                 count1++;
             }
             else if(nums[i]==num2)
             {
                 count2++;
             }
             else if(count1==0)
             {
                 num1=nums[i];
                 count1=1;
             }
             else if(count2==0)
             {
                 num2=nums[i];
                 count2=1;
             }
             else
             {
                 count1--;
                 count2--;
             }
         }
         vector<int>ans;
         count1=count2=0;
         for(i=0;i<n;i++)
         {
             if(nums[i]==num1)
             {
                 count1++;
             }
             else if(nums[i]==num2)
             {
                 count2++;
             }
         }
         
         if(count1>n/3)
         {
             ans.push_back(num1);
         }
         if(count2>n/3)
         {
             ans.push_back(num2);
         }
         return ans;
     }      
};
