class Solution {
public:
    // tc:o(n)
    // sc:o(n)
    // int missingNumber(vector<int>& nums)
    // {
    //     int ans;
    //     int n=nums.size();
    //     unordered_map<int,int>mp(n+1,0);
    //     for(int i=0;i<n;i++)
    //     {
    //         mp[nums[i]]++;
    //     }
    //     for(auto x:mp)
    //     {
    //         if(x.second==0)
    //         {
    //             ans=x.first;
    //         }
    //     }
    //     return ans;
    // }
    
    
    // tc : o(nlogn)+o(n)
    // sc:o(1)
    // case of integer overflow
    // calculated sum approach 
    int missingNumber(vector<int>& nums)
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int x=nums[n-1];
        
        int calculatedsum= n*(n+1)/2;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        int missing=calculatedsum-sum;
        return missing;
    }
    
    // most optimal solution 
    // tc:O(N)
    // sc:O(1)
    int missingNumber(vector<int>& nums)
    {
       int result=0;
        for(int i=0;i<nums.size();i++)
        {
            result=result^(nums[i]^(i+1));
        }
        return result;
    }
};
