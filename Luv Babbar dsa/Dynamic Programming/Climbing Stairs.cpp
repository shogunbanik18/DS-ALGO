
// class Solution 
// {
// public:
    
//     int f(int n)
//     {
//         if(n==0 or n==1)
//         {
//             return 1;
//         }
        
//         return f(n-1)+f(n-2);
//     }
    
//     int climbStairs(int n)
//     {
//         return f(n);       
//     }
// };


// class Solution 
// {
// public:
    
//     int f(int n,vector<int>& dp)
//     {
//         if(n==0 or n==1)
//         {
//             return 1;
//         }
        
//         if(dp[n] != -1)
//         {
//             return dp[n];
//         }
        
//         return dp[n] = f(n-1,dp) + f(n-2,dp);
//     }
    
//     int climbStairs(int n)
//     {
//         vector<int>dp(n+1,-1);
//         return f(n,dp);       
//     }
// };

class Solution 
{
public:
 
    int climbStairs(int n)
    {
        vector<int>dp(n+1,0);
        
        dp[0] =1;
        dp[1] = 1;
        
        for(int ind = 0; ind <n;ind++)
        {
            dp[n] = dp[n-1] + dp[n-2];
        }
        
        return dp[n];       
    }
};

