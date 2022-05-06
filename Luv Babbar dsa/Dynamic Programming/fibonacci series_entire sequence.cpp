// using recursion 
#include<bits/stdc++.h>
using namespace std;

// int fib(int n)
// {
//     if(n==0)
//     {
//         return 0;
//     }
    
//     if(n==1)
//     {
//         return 1;
//     }
    
//     return fib(n-1) + fib(n-2);
// }

// // memoisation 
// int fib(int n,vector<int>&dp)
// {
//     if(n==0)
//     {
//         return 0;
//     }
    
//     if(n==1)
//     {
//         return 1;
//     }
    
//     if(dp[n]!=-1)
//     {
//         return dp[n];
//     }
    
//     return fib(n-1,dp) + fib(n-2,dp);
// }

// // tabulation dp 
// int fib(int n,vector<int>&dp)
// {
//     dp[0] = 0;
//     dp[1] = 1;
    
//     for(int i = 2; i<=n; i++)
//     {
//         dp[i] = dp[i-1] + dp[i-2];
//     }
    
//     return dp[n];
// }

// without recursion 
// tabulation dp + space optimisation 
// tc : o(n)
// sc : o(1)
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
    
    int prev2 = 0;
    int prev1 = 1;
    
    for(int i = 2; i<=n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    int n;
    cin>>n;
    
    for(int i = 0;i<=n;i++)
    {
        cout<<fib(i)<<" ";
        // cout<<a<<" ";
    }
   
    return 0 ;
}
