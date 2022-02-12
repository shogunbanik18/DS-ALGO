// Greedy cannt be applied due to law of uniformity 
// // using Recursion 
// // tc:o(2^n)
// // sc:o(n)
int f(int ind,int maxWeight,vector<int>& weight,vector<int>& value)
{
	if(ind==0)
    {
        if(weight[ind]<=maxWeight)
        {
            return value[0];
        }
        return 0;
    }
    int nottake =0+f(ind-1,maxWeight,weight,value);
    int take=INT_MIN;
    if(weight[ind]<=maxWeight)
    {
        take = value[ind]+f(ind-1,maxWeight-weight[ind],weight,value);
    }
    return max(take,nottake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return f(n-1,maxWeight,weight,value);
}

// using Memoisation 
// tc:o(n*maxweight)
// sc:o(n*maxweight) +o(n)
int f(int ind,int maxWeight,vector<int>& weight,vector<int>& value,vector<vector<int>>&dp)
{
	if(ind==0)
    {
        if(weight[ind]<=maxWeight)
        {
            return value[0];
        }
        return 0;
    }
    if(dp[ind][maxWeight]!=-1)
    {
        return dp[ind][maxWeight];
    }
    int nottake =0+f(ind-1,maxWeight,weight,value,dp);
    int take=INT_MIN;
    if(weight[ind]<=maxWeight)
    {
        take = value[ind]+f(ind-1,maxWeight-weight[ind],weight,value,dp);
    }
    return dp[ind][maxWeight]=max(take,nottake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	return f(n-1,maxWeight,weight,value,dp);
}

// using Tabulation dp
// Bottom up dp
// tc:o(n*maxweight)
// sc:o(n*maxweight)
int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
	for(int W =wt[0];W<=maxWeight;W++)
    {
        dp[0][W]=val[0];
    }
    
    for(int ind=1;ind<n;ind++)
    {
        for(int W=0;W<=maxWeight;W++)
        {
            int nottake =0+dp[ind-1][W];
            int take=INT_MIN;
            if(wt[ind]<=W)
            {
                take = val[ind]+dp[ind-1][W-wt[ind]];
            }
        	dp[ind][W]=max(take,nottake);
        }
    }
    return dp[n-1][maxWeight];
}

// using space optimisation 
// tc:o(n*maxweight)
// sc:o(1)
int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
    vector<int>prev(maxWeight+1),curr(maxWeight+1);
	for(int W =wt[0];W<=maxWeight;W++)
    {
        prev[W]=val[0];
    }
    
    for(int ind=1;ind<n;ind++)
    {
        for(int W=0;W<=maxWeight;W++)
        {
            int nottake =0+prev[W];
            int take=INT_MIN;
            if(wt[ind]<=W)
            {
                take = val[ind]+prev[W-wt[ind]];
            }
        	curr[W]=max(take,nottake);
        }
        prev=curr;
    }
    return prev[maxWeight];
}


// using space optimisation 
// tc:o(n*maxweight)
// sc:o(n*maxweight)
int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
    vector<int>prev(maxWeight+1);
	for(int W =wt[0];W<=maxWeight;W++)
    {
        prev[W]=val[0];
    }
    
    for(int ind=1;ind<n;ind++)
    {
        for(int W=maxWeight;W>=0;W--)
        {
            int nottake =0+prev[W];
            int take=INT_MIN;
            if(wt[ind]<=W)
            {
                take = val[ind]+prev[W-wt[ind]];
            }
        	prev[W]=max(take,nottake);
        }
    }
    return prev[maxWeight];
}
