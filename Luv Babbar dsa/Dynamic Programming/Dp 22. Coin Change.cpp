// Note : All the solutions are valid for coins>=1 
// using Recursion 
// tc: exponential >>> 2^n
// sc: o(target) in worst case 
int f(int ind,int target,int*arr)
{
    if(ind==0)
    {
        return (target%arr[ind]==0);
    }
    int nottake = f(ind-1,target,arr);
    int take=0;
    if(arr[ind]<=target)
    {
        take =f(ind,target-arr[ind],arr);
    }
    return take+nottake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    return f(n-1,value,denominations);
}


// using Memoisation 
// Top down dp 
// tc: o(n*target)
// sc: o(n*target) + o(target) extra auxiliary stack space
#include<bits/stdc++.h>
int f(int ind,int target,int*arr, vector<vector<long>>&dp)
{
    if(ind==0)
    {
        return (target%arr[ind]==0);
    }
    if(dp[ind][target]!=-1)
    {
        return dp[ind][target];
    }
    long nottake = f(ind-1,target,arr,dp);
    long take=0;
    if(arr[ind]<=target)
    {
        take =f(ind,target-arr[ind],arr,dp);
    }
    return dp[ind][target]=take+nottake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>>dp(n,vector<long>(value+1,-1));
    return f(n-1,value,denominations,dp);
}

// using Tabulation dp 
// Bottom up dp 
// tc: o(n*target)
// sc: o(n*target) 
// long countWaysToMakeChange(int *arr, int n, int value)
// {
//     vector<vector<long>>dp(n,vector<long>(value+1,0));
//     for(int target=0;target<=value;target++)
//     {
//        dp[0][target]=(target%arr[0]==0);
//     }
//     for(int ind=1;ind<n;ind++)
//     {
//         for(int target=0;target<value;target++)
//         {
//             long nottake = dp[ind-1][target];
//             long take=0;
//             if(arr[ind]<=target)
//             {
//                 take =dp[ind][target-arr[ind]];
//             }
//             dp[ind][target]=take+nottake;
//         }
//     }
//     return dp[n-1][value];
// }
