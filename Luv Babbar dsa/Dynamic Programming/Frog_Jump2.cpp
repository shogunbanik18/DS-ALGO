#include<bits/stdc++.h>
using namespace std;

// using simple recursion 
int f(int ind,vector<int>&heights)
{
    if(ind==0)
    {
        return 0;
    }
    
    int minsteps=INT_MAX;
    for(int j=1;j<=k;j++)
    {
            if((ind-j)>0)
        int jump= f(ind-j,heights)+abs(heights[ind]-heights[ind-j]);
        minsteps=min(minsteps,jump);
    }
    return minsteps;
}

int frogJump(int n, vector<int> &heights)
{
    return f(n-1,heights);
}


//  using dp memoisation 
// tc:O(N)*K
// sc:O(N)
int f(int ind,vector<int>&heights, vector<int>&dp)
{
    if(ind==0)
    {
        return 0;
    }
    
    if(dp[ind]!=-1)
    {
        return dp[ind];
    }
    int minsteps=INT_MAX;
    for(int j=1;j<=k;j++)
    {
            if((ind-j)>0)
        int jump= dp[ind-j]+abs(heights[ind]-heights[ind-j]);
        minsteps=min(minsteps,jump);
    }
    return dp[ind]=minsteps;
}

int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1,-1);
    return f(n-1,heights,dp);
}
