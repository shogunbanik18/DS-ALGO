#include<bits/stdc++.h>
using namespace std;

// // using recursion 
// tc : o(n)
// sc : o(n) stack space 
// int fact(int n)
// {
//     if(n==0 or n==1)
//     {
//         return 1;
//     }
    
//     return n*fact(n-1);
// }


// using recursion 
// tc : o(n)
// sc : o(n) stack space 
int fact(int n,vector<int>&dp)
{
    if(n==0 or n==1)
    {
        return 1;
    }
    
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    
    return dp[n] = n*fact(n-1,dp);
}


// // using Tabulation 
// // tc : o(n)
// // sc : o(n) stack space 
// int fact(int n,vector<int>&dp)
// {
//     if(n>=0)
//     {
//          dp[0] =1;
        
//         for(int i = 1 ;i<=n;i++)
//         {
//             dp[i] = i*dp[i-1];
//         }
        
//         return dp[n];
//     }
// }


// using Tabulation 
// tc : o(n)
// sc : o(n) stack space 
// int fact(int n,vector<int>&dp)
// {
//     if(n>=0)
//     {
//         int prev =1;
//         int curr;
        
//         for(int i = 1 ;i<=n;i++)
//         {
//             curr = i*prev;
//             prev = curr;
//         }
        
//         return prev;
//     }
// }


// // using iteration 
// int fact(int n)
// {
//     int ans = 1;
//     for(int i =1;i<=n;i++)
//     {
//         ans = ans *i;
//     }
//     return ans;
// }

int main()
{
    int n;
    cin>> n;

    vector<int>dp(n+1,-1);
    int ans = fact(n,dp); 
    cout<<ans<<endl;
    
    return 0;
}
