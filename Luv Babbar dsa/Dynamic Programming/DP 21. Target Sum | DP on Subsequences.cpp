// similar to partition subsets with s1-s2=d
class Solution {
public:
    
    // recursion + memoisation 
    int f(int ind,int target,vector<int>&arr, vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            if(target==0 and arr[0]==0)
            {
                return 2;
            }
            if(target==0 or target==arr[0])
            {
                return 1;
            }
            return 0;
        }
        if(dp[ind][target]!=-1)
        {
            return dp[ind][target];
        }
        int nottake = f(ind-1,target,arr,dp);
        int take=0;
        if(arr[ind]<=target)
        {
            take= f(ind-1,target-arr[ind],arr,dp);
        }
        return dp[ind][target]=(take+nottake);
    }
    
    int findWays(vector<int> &num, int tar)
    {
        int n=num.size();
        vector<vector<int>>dp(n,vector<int>(tar+1,-1));
        return f(n-1,tar,num,dp);
    }

    
    // using tabulation form 
//     int findWays(vector<int> &num, int tar)
//     {
//         int n=num.size();
//         vector<vector<int>>dp(n,vector<int>(tar+1,0));
//         if(num[0]==0)
//         {
//               dp[0][0]=2;
//         }
//         else
//         {
//             dp[0][0]=1;
//         }

//         if(num[0]!=0 and num[0]<=tar)
//         {
//             dp[0][num[0]]=1;
//         }
//         for(int ind=1;ind<n;ind++)
//         {
//             for(int sum=0;sum<=tar;sum++)
//             {
//                     int nottake =dp[ind-1][sum];
//                     int take=0;
//                     if(num[ind]<=sum)
//                     {
//                         take=dp[ind-1][sum-num[ind]];
//                     }
//                     dp[ind][sum]=(take+nottake);
//             }
//         }
//         return dp[n-1][tar];
//     }
    
    // using space optimised form 
//     int findWays(vector<int> &num, int tar)
//     {
//         int n=num.size();
//         vector<int>prev(tar+1,0),curr(tar+1,0);
//         if(num[0]==0)
//         {
//               prev[0]=2;
//         }
//         else
//         {
//             prev[0]=1;
//         }

//         if(num[0]!=0 and num[0]<=tar)
//         {
//             prev[num[0]]=1;
//         }
//         for(int ind=1;ind<n;ind++)
//         {
//             for(int sum=0;sum<=tar;sum++)
//             {
//                     int nottake =prev[sum];
//                     int take=0;
//                     if(num[ind]<=sum)
//                     {
//                         take=prev[sum-num[ind]];
//                     }
//                     curr[sum]=(take+nottake);
//             }
//             prev=curr;
//         }
//         return prev[tar];
//     }
    
    int countpartitions(int n, int target, vector<int> &arr) 
    {
        int totalsum=0;
        for(auto x:arr )
        {
            totalsum+=x;
        }
        if(totalsum-target<0 or (totalsum-target)%2!=0)
        {
            return false;
        }
        return findWays(arr,(totalsum-target)/2);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n=nums.size();
        return countpartitions(n,target,nums);
    }
};
