class Solution {
public:
    // using recursion
    // tc:O(2^N)
    // int f(int n)
    // {
    //     if(n==0)
    //     {
    //         return 0;
    //     }
    //     if(n==1)
    //     {
    //         return 1;
    //     }
    //     if(n==2)
    //     {
    //         return 1;
    //     }
    //     return f(n-1)+f(n-2)+f(n-3);
    // }
    // int tribonacci(int n)
    // {
    //     return f(n);
    // }
    
    // using memoisation
    // tc:O(n)
    // sc:o(n)+o(n)
    int f(int n,vector<long long int>&dp)
    {
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
        if(n==2)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return dp[n]=f(n-1,dp)+f(n-2,dp)+f(n-3,dp);
    }
    // taking care of n 
    int tribonacci(int n)
    {
        vector<long long >dp(38,-1);
        return f(n,dp);
    }
    
};
