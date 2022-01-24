class Solution {
public:
    // using recursion
    // tc:o(2^n)
    // sc:o(1)
    int checkclimb(int ind)
    {
        // base case 
        if(ind==0 )
        {
            return 1;
        }
        if(ind==1)
        {
            return 1;
        }
        return checkclimb(ind-1)+checkclimb(ind-2);
    }
    
    int climbStairs(int n) 
    {
        return checkclimb(n);
    }
    
    // tc :O(n)
    // sc:O(n)
    // using memoisation 
    int checkclimb(int ind,vector<int>&dp)
    {
        // base case 
        if(ind==0 )
        {
            return 1;
        }
        if(ind==1)
        {
            return 1;
        }
        
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        return dp[ind]=checkclimb(ind-1,dp)+checkclimb(ind-2,dp);
    }
    
    int climbStairs(int n) 
    {
        vector<int>dp(n+1,-1);
        return checkclimb(n,dp);
    }
};
