#include<bits/stdc++.h>
using namespace std;
// fibonacci number using dp

// Memoization Approach 
// tc: O(N)
// sc :O(N)+O(N) for array
int fib(int n,vector<int>&dp)
{
    if(n==0 or n==1)
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
    vector<int>dp(n+1,-1);
    cout<<fib(n,dp);
    return 0;
}
