// Leetcode 
class Solution {
public:
    // using recursion 
    // tc: >>>o(2^n)
    // sc: o(target)
    int f(int ind,int target,vector<int>&coins)
    {
        if(ind==0)
        {
            return (target % coins[0]==0);
        }
        int nottake= f(ind-1,target,coins);
        int take=0;
        if(coins[ind]<=target)
        {
            take=f(ind,target-coins[ind],coins);
        }
        return take+nottake;
    }
    
    int change(int amount, vector<int>& coins) 
    {
        int n=coins.size();
        return f(n-1,amount,coins);
    }
    
    // using memeoisation 
    // top down dp 
    // tc:o(n*target)
    // sc: o(n*target) + o(target) auxiliary stack space
    int f(int ind,int target,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            return (target % coins[0]==0);
        }
        if(dp[ind][target]!=-1)
        {
            return dp[ind][target];
        }
        int nottake= f(ind-1,target,coins,dp);
        int take=0;
        if(coins[ind]<=target)
        {
            take=f(ind,target-coins[ind],coins,dp);
        }
        return dp[ind][target]=take+nottake;
    }
    
    int change(int amount, vector<int>& coins) 
    {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
    

    // using Tabulation dp  
    // Bottom up dp 
    // tc:o(n*target)
    // sc: o(n*target)   
    int change(int amount, vector<int>& coins) 
    {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int target=0;target<=amount;target++)
        {
            dp[0][target]=(target %coins[0]==0);
        }
        
        for(int ind=1;ind<n;ind++)
        {
            for(int target=0;target<=amount;target++)
            {
                int nottake= dp[ind-1][target];
                int take=0;
                if(coins[ind]<=target)
                {
                    take=dp[ind][target-coins[ind]];
                }
                dp[ind][target]=take+nottake;
            }
        }
        return dp[n-1][amount];
    }
    
    
    // using Tabulation dp  
    // Bottom up dp 
    // tc:o(n*target)
    // sc: o(target)  
    int change(int amount, vector<int>& coins) 
    {
        int n=coins.size();
        vector<int>prev(amount+1,0),curr(amount+1,0);
        for(int target=0;target<=amount;target++)
        {
            prev[target]=(target %coins[0]==0);
        }
        
        for(int ind=1;ind<n;ind++)
        {
            for(int target=0;target<=amount;target++)
            {
                int nottake= prev[target];
                int take=0;
                if(coins[ind]<=target)
                {
                    take=curr[target-coins[ind]];
                }
                curr[target]=take+nottake;
            }
            prev=curr;
        }
        return prev[amount];
    }
    
};
