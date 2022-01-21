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
