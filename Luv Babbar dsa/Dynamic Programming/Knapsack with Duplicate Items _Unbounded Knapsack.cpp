// gfg 
class Solution{
public:
    // // using Recursion
    // // tc: >>>> o(2^n) Exponential 
    // // sc:o(target)
    int f(int ind,int target,int *val,int *wt)
    {
        if(ind==0)
        {
            return ((int)( target/wt[0]))*val[0];
        }
        int nottake = 0 +f(ind-1,target,val,wt);
        int take =INT_MIN;
        if(wt[ind]<=target)
        {
            take = val[ind] +f(ind,target-wt[ind],val,wt);
        }
        return max(take,nottake);
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        return f(N-1,W,val,wt);
    }
    
    // using Memoisation
    // tc:o(n*target)
    // sc:o(n*target)+ o(target)
    int f(int ind,int target,int *val,int *wt,vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            return ((int)( target/wt[0]))*val[0];
        }
        if(dp[ind][target]!=-1)
        {
          return  dp[ind][target]; 
        }
        int nottake = 0 +f(ind-1,target,val,wt,dp);
        int take =INT_MIN;
        if(wt[ind]<=target)
        {
            take = val[ind] +f(ind,target-wt[ind],val,wt,dp);
        }
        return dp[ind][target]=max(take,nottake);
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return f(N-1,W,val,wt,dp);
    }
    
    // // using Tabulation
    // // Bottom up dp 
    // // tc:o(n*target)
    // // sc:o(n*target)
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N,vector<int>(W+1,0));
        for(int w=0;w<=W;w++)
        {
            dp[0][w] = ((int)(w/wt[0]))*val[0];
        }
        
        for(int ind=1;ind<N;ind++)
        {
            for(int target=0;target<=W;target++)
            {
                int nottake = 0 +dp[ind-1][target];
                int take =INT_MIN;
                if(wt[ind]<=target)
                {
                    take = val[ind] +dp[ind][target-wt[ind]];
                }
                dp[ind][target]=max(take,nottake);
            }
        }
        return dp[N-1][W];
    }
    
    // // using Sapace Optimisation to 2 array 
    // // Bottom up dp 
    // // tc:o(n*target)
    // // sc:o(target)
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int>prev(W+1,0),curr(W+1,0);
        for(int w=0;w<=W;w++)
        {
            prev[w] = ((int)(w/wt[0]))*val[0];
        }
        
        for(int ind=1;ind<N;ind++)
        {
            for(int target=0;target<=W;target++)
            {
                int nottake = 0 +prev[target];
                int take =INT_MIN;
                if(wt[ind]<=target)
                {
                    take = val[ind] +curr[target-wt[ind]];
                }
                curr[target]=max(take,nottake);
            }
            prev=curr;
        }
        return prev[W];
    }
    
    // using Sapace Optimisation to 1 array 
    // Bottom up dp 
    // tc:o(n*target)
    // sc:o(target)
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int>prev(W+1,0);
        for(int w=0;w<=W;w++)
        {
            prev[w] = ((int)(w/wt[0]))*val[0];
        }
        
        for(int ind=1;ind<N;ind++)
        {
            for(int target=0;target<=W;target++)
            {
                int nottake = 0 +prev[target];
                int take =INT_MIN;
                if(wt[ind]<=target)
                {
                    take = val[ind] +prev[target-wt[ind]];
                }
                prev[target]=max(take,nottake);
            }
        }
        return prev[W];
    }
};
