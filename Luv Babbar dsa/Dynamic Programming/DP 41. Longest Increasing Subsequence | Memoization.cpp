// using Recursion
// tc : o(2^n)
// sc : o(1)
int f(int ind, int prevind, int *nums ,int n)
    {
        if(ind==n)
        {
            return 0;
        }
        
        int nottake = 0 + f(ind+1, prevind ,nums,n);
        
        int take = 0;
        if(nums[ind] > nums[prevind] or prevind==-1 )
        {
            take += 1 + f(ind+1 ,ind , nums, n);
        }
        
        return max(take,nottake);
}  
    

int longestIncreasingSubsequence(int arr[], int n)
{
    return f(0,-1,arr,n);
}

// using dp 
// runtime error  array of size 10^10

// tc : o(n*n)
// sc : o(n*n) + o(n)
#include<bits/stdc++.h>
int f(int ind, int prevind, int *nums ,int n , vector<vector<int>>& dp)
    {
        if(ind==n)
        {
            return 0;
        }
        
    	if(dp[ind][prevind+1] !=-1)
        {
            return dp[ind][prevind+1];
        }
    
        int nottake = 0 + f(ind+1, prevind ,nums,n,dp);
        
        int take = 0;
        if(nums[ind] > nums[prevind] or prevind==-1 )
        {
            take += 1 + f(ind+1 ,ind , nums, n,dp);
        }
        
        return dp[ind][prevind+1] = max(take,nottake);
}  
    

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return f(0,-1,arr,n,dp);
}
