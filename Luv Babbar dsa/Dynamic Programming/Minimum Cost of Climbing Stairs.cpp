class Solution {
public:
    // using recursion 
    // tc:O(2^n)
    // sc:o(1)
    int f(int ind,vector<int>&cost)
    {
        if(ind==0 or ind==1)
        {
            return cost[ind];
        }
        if(ind<0)
        {
            return 0;
        }
        int take = f(ind-2,cost);
        int nottake=0+ f(ind-1,cost);
        return cost[ind]+min(take,nottake);
    }
    
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n=cost.size();
        return min(f(n-1,cost),f(n-2,cost));
    }
    
//     using top down dp memeoisation approach 
    int f(int ind,vector<int>&cost,vector<int>&dp)
    {
        if(ind==0 or ind==1)
        {
            return cost[ind];
        }
        if(ind<0)
        {
            return 0;
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        int take = f(ind-2,cost,dp);
        int nottake=0+ f(ind-1,cost,dp);
        return dp[ind]=cost[ind]+min(take,nottake);
    }
    
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(f(n-1,cost,dp),f(n-2,cost,dp));
    }
};
