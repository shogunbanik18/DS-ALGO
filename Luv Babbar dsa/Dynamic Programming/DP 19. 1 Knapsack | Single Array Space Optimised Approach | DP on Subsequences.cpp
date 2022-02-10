class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    // Greedy Aalgorithm cannot be applied due to uniformity 
    
    // // using recursion
    // // tc: O(2^n)
    // // sc:o(n) auxiliary stack space 
    int f(int ind,int W,int *wt,int *val)
    {
        // base case 
        if(ind==0)
        {
            if(wt[0]<=W)
            {
                return val[0];
            }
            return 0;
        }
        int notpick= 0+ f(ind-1,W,wt,val);
        int pick=INT_MIN;
        if(wt[ind]<=W)
        {
            pick=val[ind]+f(ind-1,W-wt[ind],wt,val);
        }
        return max(pick,notpick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       return f(n-1,W,wt,val);
      // Your code here
    }
    
    
    // using Memoisation
    // tc: O(n*wt)
    // sc: O(n*wt)+O(n) auxiliary stack space 
    int f(int ind,int W,int *wt,int *val,vector<vector<int>>&dp)
    {
        // base case 
        if(ind==0)
        {
            if(wt[0]<=W)
            {
                return val[0];
            }
            return 0;
        }
        if(dp[ind][W]!=-1)
        {
            return dp[ind][W];
        }
        int notpick= 0+ f(ind-1,W,wt,val,dp);
        int pick=INT_MIN;
        if(wt[ind]<=W)
        {
            pick=val[ind]+f(ind-1,W-wt[ind],wt,val,dp);
        }
        return dp[ind][W]=max(pick,notpick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return f(n-1,W,wt,val,dp);
    }
    
    
    // Tabulation 
    // Bottom up dp 
    // tc: O(n*wt)
    // sc: O(n*wt)
    // int knapSack(int W, int wt[], int val[], int n) 
    // { 
    //     vector<vector<int>>dp(n,vector<int>(W+1,0));
    //     // base case 
    //     for(int i=wt[0];i<=W;i++)
    //     {
    //         dp[0][i]=val[0];
    //     }
        
    //     for(int ind=1;ind<n;ind++)
    //     {
    //         for(int weight=0;weight<=W;weight++)
    //         {
    //             int notpick= 0+ dp[ind-1][weight];
    //             int pick=INT_MIN;
    //             if(wt[ind]<=W)
    //             {
    //                 pick=val[ind]+dp[ind-1][weight-wt[ind]];
    //             }
    //             dp[ind][weight]=max(pick,notpick);
    //         }
    //     }
    //     return dp[n-1][W];
    // }
};
