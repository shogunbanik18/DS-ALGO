#include<bits/stdc++.h>
using namespace std;

// using simple recursion 
int f(int ind,vector<int>&heights)
{
    if(ind==0)
    {
        return 0;
    }
    
    int left= f(ind-1,heights)+abs(heights[ind]-heights[ind-1]);
    int right=INT_MAX;
    if(ind>1)
    {
        right= f(ind-2,heights)+abs(heights[ind]-heights[ind-2]);
    }
    return min(left,right);
}

int frogJump(int n, vector<int> &heights)
{
    return f(n-1,heights);
    // Write your code here.
}

//  using dp memoisation 
// tc:O(N)
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
    int left=f(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
    int right=INT_MAX;
    if(ind>1)
    {
        right= f(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
    }
    return dp[ind]=min(left,right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1,-1);
    return f(n-1,heights,dp);
    // Write your code here.
}


// tabular form 
// using bottom up dp 
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int fs=dp[i-1]+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1)
        {
            ss=dp[i-2]+abs(heights[i]-heights[i-2]);
        }
        dp[i]=min(fs,ss);  
    }
    return dp[n-1];
    // Write your code here.
}

// Most Optimized Code 
// space optmization using tabular form 
// tc: o(N)
// sc:O(1)
int frogJump(int n, vector<int> &heights)
{
    int prev2=0;
    int prev1=0;
    for(int i=1;i<n;i++)
    {
        int fs=prev1+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1)
        {
            ss=prev2+abs(heights[i]-heights[i-2]);
        }
        int curri=min(fs,ss);
        prev2=prev1;
        prev1=curri;
    }
    return prev1;
    // Write your code here.
}
