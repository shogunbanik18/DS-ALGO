#include<bits/stdc++.h>
using namespace std;

// using  Iteration
// Bottom up dp 
void fib(int n)
{
    int prev2=0,prev1=1;
    for(int i=0;i<n;i++)
    {
        cout<<prev2<<" ";
        int curr=prev2+prev1;
        prev2=prev1;
        prev1=curr;
    }
}

int main()
{
    int n;
    cin>>n;
    fib(n);
    return 0;
}

// using recursion 
int fib(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    return fib(n-1)+fib(n-2);
}

int main()
{   
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<fib(i)<<" ";
    }
    return 0;
}

// Using dynamic programming 
// memoisation Top Down 
int fib(int n,vector<int>&dp)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}

int main()
{   
    int n;
    cin>>n;
    vector<int>dp(n,-1);
    for(int i=0;i<n;i++)
    {
        cout<<fib(i,dp)<<" ";
    }
    return 0;
}

// Using dynamic programming 
// Tabulation Bottom up  
int fib(int n,vector<int>&dp)
{
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n-1];
}

int main()
{   
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    
    for(int i=1;i<n;i++)
    {
        cout<<fib(i,dp)<<" ";
    }
    return 0;
}

// Using dynamic programming 
// Tabulation Bottom up 
// Space optimisation 
void fib(int n)
{
    int prev2=0,prev1=1;
    for(int i=0;i<n;i++)
    {
        cout<<prev2<<" ";
        int curr=prev2+prev1;
        prev2=prev1;
        prev1=curr;
    }
}

int main()
{   
    int n;
    cin>>n;
    fib(n);
    return 0;
}
