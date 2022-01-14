class Solution {
public:
    // tc :O(n)
    // sc:O(n)
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
