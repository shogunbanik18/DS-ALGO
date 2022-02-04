class Solution {
public:
    // using the concept of susbset sum equal to k
        // // using Recursion  concept 
        // bool f(int ind,int target,vector<int> &arr)
        // {
        // //     base case 
        //     if(target==0)
        //     {
        //         return true;
        //     }
        //     if(ind==0)
        //     {
        //        return (arr[0]==target);
        //     }
        // //     take / not take concept 
        //     bool nottake=f(ind-1,target,arr);
        //     bool take=false;
        //     if(target>=arr[ind])
        //     {
        //         take=f(ind-1,target-arr[ind],arr);
        //     }
        //     return (take|nottake);
        // }
        // bool subsetsum(int n, int k, vector<int> &arr) 
        // {
        //     return f(n-1,k,arr);
        //     // Write your code here.
        // }
    
    // using memoisation concept 
    // bool f(int ind,int target,vector<int> &arr,vector<vector<int>>&dp)
    // {
    //     if(target==0)
    //     {
    //         return true;
    //     }
    //     if(ind==0)
    //     {
    //        return (arr[0]==target);
    //     }
    //     if(dp[ind][target]!=-1)
    //     {
    //         return dp[ind][target];
    //     }
    //     bool nottake=f(ind-1,target,arr,dp);
    //     bool take=false;
    //     if(target>=arr[ind])
    //     {
    //         take=f(ind-1,target-arr[ind],arr,dp);
    //     }
    //     return dp[ind][target]=(take|nottake);
    // }
    // bool subsetsum(int n, int k, vector<int> &arr) 
    // {
    //     vector<vector<int>>dp(n,vector<int>(k+1,-1));
    //     return f(n-1,k,arr,dp);
    // }
    
    
    // using bottom up
    // tabulation appraoch 
    //  bool subsetsum(int n, int k, vector<int> &arr) 
    // {
    //     vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    //     for(int i=0;i<n;i++)
    //     {
    //         dp[i][0]=true;
    //     }
    //     dp[0][arr[0]]=true;
    //     for(int ind=1;ind<n;ind++)
    //     {
    //         for(int target=1;target<=k;target++)
    //         {
    //             bool nottake=dp[ind-1][target];
    //             bool take=false;
    //             if(target>=arr[ind])
    //             {
    //                 take+=dp[ind-1][target-arr[ind]];
    //             }
    //             dp[ind][target]=take|nottake;
    //         }
    //     }
    //     return dp[n-1][k];
    // }
    

    // tc:o(n*target)+o(n)
    // sc:o(1)
    bool subsetsum(int n, int k, vector<int> &arr) 
    {
        vector<bool>prev(k+1,0),curr(k+1,0);
        prev[0]=curr[0]=true;
        if(k>=arr[0])
        {
            prev[arr[0]]=true;
        }
        for(int ind=1;ind<n;ind++)
        {
            for(int target=1;target<=k;target++)
            {
                bool nottake=prev[target];
                bool take=false;
                if(target>=arr[ind])
                {
                    take=prev[target-arr[ind]];
                }
               curr[target]=(take|nottake);
            }
            prev=curr;
        }
        return prev[k];
    }
    
    bool canPartition(vector<int>& nums) 
    {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2)
        {
            return false;
        }
        int target=sum/2;
        return subsetsum(n,target,nums);
    }
};
