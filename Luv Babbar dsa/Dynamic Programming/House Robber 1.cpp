class Solution {
public:
    // using recursion and dp memoisation 
    // tc:O(2^n)
    // sc:O(n) +o(n)
//     int maximumrobber(int ind,vector<int>&nums,vector<int>&dp)
//     {
//         if(ind==0)
//         {
//             return nums[0];
//         }
        
//         if(ind<1)
//         {
//             return 0;
//         }
        
//         if(dp[ind]!=-1)
//         {
//             return dp[ind];
//         }
//         int pick=nums[ind]+maximumrobber(ind-2,nums,dp);
//         int notpick=0+maximumrobber(ind-1,nums,dp);
//         return dp[ind]=max(pick,notpick);
//     }
        //  int rob(vector<int>& nums)
        // {
        //     int n=nums.size();
        //     vector<int>dp(n+1,-1);
        //     return maximumrobber(n-1,nums,dp);   
        // }

    // Using Bottom up dp approach  
//      int maximumrobber(vector<int>&nums)
//     {
//          int n=nums.size();
//          vector<int>dp(n+1,-1);
//          dp[0]=nums[0];
//          int neg=0;
         
//          for(int i=1;i<n;i++)
//          {
//              int take =nums[i];
//              if(i>1)
//              {
//                  take+=dp[i-2];
//              }
//              int nottake=0+dp[i-1];
//              dp[i]=max(take,nottake);
//          }
//         return dp[n-1];
//     }
    
    // Bottom Up dp with space optimisation 
    // tc:o(2^n)
    // sc:o(1)
    int maximumrobber(vector<int>&nums)
    {
         int n=nums.size();
         int prev1=nums[0];
         int prev2=0;
         
         for(int i=1;i<n;i++)
         {
             int take =nums[i];
             if(i>1)
             {
                 take+=prev2;
             }
             int nottake=0+prev1;
             int curri=max(take,nottake);
             prev2=prev1;
             prev1=curri;
         }
        return prev1;
    }
    
    int rob(vector<int>& nums)
    {
        return maximumrobber(nums);   
    }
};
