class Solution {
public:
    
    // using brute force 
    // tc:O(N^2)
    // SC:O(1)
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
    
    // most efficient 
    // using hashmap
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int x=target-nums[i];
            if(mp.find(x)!=mp.end())
            {
                ans.push_back(mp[x]);
                ans.push_back(i);
            }
            // storing the index 
            mp[nums[i]]=i;
        }
        return ans;
    }
    
    // sorting changes the index here so dont use two pointer appraoch
    // using 2 pointer approach 
    // Time Complexity: O(NlogN)
    // Space Complexity: O(N)
     // vector<int> twoSum(vector<int>& nums, int target)
     //    {
     //        vector<int>ans;
     //        int n=nums.size();
     //        sort(nums.begin(),nums.end());
     //        int i=0;
     //        int j=n-1;
     //        while(i<j)
     //        {
     //            if(nums[i]+nums[j]==target)
     //            {
     //                ans.push_back(i);
     //                ans.push_back(j);
     //                return ans;
     //            }
     //            else if(nums[i]+nums[j]>target)
     //            {
     //                j--;
     //            }
     //            else
     //            {
     //                i++;
     //            }
     //        }
     //        return ans;
     //    }
};




// leetcode 

class Solution {
public:
    // brute force 
    // tc:o(n^2)
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
    
    // using hashmap based approach 
    // tc:o(n)
    // sc:o(n)
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int>v;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                v.push_back(i);
                v.push_back(mp[target-nums[i]]);
            }
            mp[nums[i]]=i;
        }
        return v;
    }
    
    // using 2 pointer approach 
    // sorting changes the index so sorting s not preferred 
    // and hence two pointer should not be used here
    // vector<int> twoSum(vector<int>& nums, int target) 
    // {
    //     vector<int>v;
    //     sort(nums.begin(),nums.end());
    //     int n=nums.size();
    //     int low=0;
    //     int high=n-1;
    //     while(low<high)
    //     {
    //         if(nums[low]+nums[high]==target)
    //         {
    //             v.push_back(low);
    //             v.push_back(high);
    //             break;
    //         }
    //         else if(nums[low]+nums[high]<target)
    //         {
    //             low++;
    //         }
    //         else
    //         {
    //             high--;
    //         }
    //     }
    //     return v;
    // }
};
