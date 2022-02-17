// // using recursion
// // tc: >> o(2^n)
// // sc  : o(target) 
int f(int ind,int target,vector<int> &val, vector<int> &wt)
{
    if(ind==0)
    {
        return ((int) ( target/wt[0]))* val[0];
    }
    int nottake = 0 +f(ind-1,target,val,wt);
    int take=0;
    if(wt[ind]<=target)
    {
        take = val[ind] + f(ind,target-wt[ind],val,wt); 
    }
    return max (take,nottake);
}
int unboundedKnapsack(int n, int target, vector<int> &val, vector<int> &wt)
{
    return f(n-1,target,val,wt);
}

// using Memoisation 
// Top Down Dp
// tc:o(n*target)
// sc:o(n*target) + o(target) 
int f(int ind,int target,vector<int> &val, vector<int> &wt, vector<vector<int>>&dp)
{
    if(ind==0)
    {
        return ((int) ( target/wt[0]))* val[0];
    }
    if(dp[ind][target]!=-1)
    {
        return dp[ind][target];
    }
    int nottake = 0 +f(ind-1,target,val,wt,dp);
    int take=0;
    if(wt[ind]<=target)
    {
        take = val[ind] + f(ind,target-wt[ind],val,wt,dp); 
    }
    return dp[ind][target]= max (take,nottake);
}
int unboundedKnapsack(int n, int target, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    return f(n-1,target,val,wt,dp);
}

// // using Tabulation
// // Bottom Up 
// // tc:o(n*target)
// // sc:o(n*target)
#include<bits/stdc++.h>
int unboundedKnapsack(int n, int target, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    for(int i=0;i<=target;i++)
    {
        dp[0][i] = ((int) (i/wt[0])) * val[0];
    }
    
    for(int ind=1;ind<n;ind++)
    {
        for(int t=0;t<=target;t++)
        {
            int nottake = 0 +dp[ind-1][t];
            int take=INT_MIN;
            if(wt[ind]<=t)
            {
                take = val[ind] + dp[ind][t-wt[ind]]; 
            }
            dp[ind][t]= max (take,nottake);
        }
    }
    return dp[n-1][target];
}


// using Space optimisation 1
// Bottom Up 
// tc:o(n*target)
// sc:o(target)
#include<bits/stdc++.h>
int unboundedKnapsack(int n, int target, vector<int> &val, vector<int> &wt)
{
    vector<int>prev(target+1,0),curr(target+1,0);
    for(int i=0;i<=target;i++)
    {
        prev[i] = ((int) (i/wt[0])) * val[0];
    }
    
    for(int ind=1;ind<n;ind++)
    {
        for(int t=0;t<=target;t++)
        {
            int nottake = 0 +prev[t];
            int take=INT_MIN;
            if(wt[ind]<=t)
            {
                take = val[ind] + curr[t-wt[ind]]; 
            }
            curr[t]= max (take,nottake);
        }
        prev=curr;
    }
    return prev[target];
}


// using Space optimisation 2 
// 1d array 
// Bottom Up 
// tc:o(n*target)
// sc:o(target)
#include<bits/stdc++.h>
int unboundedKnapsack(int n, int target, vector<int> &val, vector<int> &wt)
{
    vector<int>prev(target+1,0);
    for(int i=0;i<=target;i++)
    {
        prev[i] = ((int) (i/wt[0])) * val[0];
    }
    
    for(int ind=1;ind<n;ind++)
    {
        for(int t=0;t<=target;t++)
        {
            int nottake = 0 +prev[t];
            int take=INT_MIN;
            if(wt[ind]<=t)
            {
                take = val[ind] + prev[t-wt[ind]]; 
            }
            prev[t]= max (take,nottake);
        }
    }
    return prev[target];
}
