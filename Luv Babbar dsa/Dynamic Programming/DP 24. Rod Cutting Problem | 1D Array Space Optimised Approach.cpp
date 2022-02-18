// Similar to Unbounded knapsack  
// // Using Recursion 
// // tc: Exponential 
// // sc :o(1)
int f(int ind,int target,vector<int>price)
{
    if(ind==0)
    {
        return target *price[0];
    }
    int nottake = 0 +f(ind-1,target,price);
    int take =INT_MIN;
    int rodlength = ind+1;
    if(rodlength<=target)
    {
        take = price[ind] + f(ind,target-rodlength,price); 
    }
    return max(take,nottake);
}
int cutRod(vector<int> &price, int target)
{
    int N =price.size();
    return f(N-1,target,price);
}

// // Using Memoisation 
// // tc: o(n*target) 
// // sc :o(n*target)+ o(target)
int f(int ind,int target,vector<int>&price,vector<vector<int>>&dp)
{
    if(ind==0)
    {
        return target *price[0];
    }
    if(dp[ind][target]!=-1)
    {
        return dp[ind][target];
    }
    int nottake = 0 +f(ind-1,target,price,dp);
    int take =INT_MIN;
    int rodlength = ind+1;
    if(rodlength<=target)
    {
        take = price[ind] + f(ind,target-rodlength,price,dp); 
    }
    return dp[ind][target]=max(take,nottake);
}
int cutRod(vector<int> &price, int target)
{
    int N =price.size();
    vector<vector<int>>dp(N,vector<int>(N+1,-1));
    return f(N-1,target,price,dp);
}


// // Using Memoisation 
// // tc: o(n*target) 
// // sc :o(n*target)
int cutRod(vector<int> &price, int target)
{
    int N =price.size();
    vector<vector<int>>dp(target,vector<int>(target+1,0));
    for(int i=0;i<=target;i++)
    {
       dp[0][i]=i*price[0];
    }
    for(int ind=1;ind<N;ind++)
    {
        for(int t=0;t<=target;t++)
        {
             int nottake = 0 +dp[ind-1][t];
            int take =INT_MIN;
            int rodlength = ind+1;
            if(rodlength<=t)
            {
                take = price[ind] +dp[ind][t-rodlength]; 
            }
           dp[ind][t]=max(take,nottake);
        }
    }
    return dp[N-1][target];
}


// Using Space optimisation 
// tc: o(n*target) 
// sc :o(target)
int cutRod(vector<int> &price, int target)
{
    int N =price.size();
    vector<int>prev(target+1,0),curr(target+1,0);
    for(int i=0;i<=target;i++)
    {
       prev[i]=i*price[0];
    }
    for(int ind=1;ind<N;ind++)
    {
        for(int t=0;t<=target;t++)
        {
             int nottake = 0 +prev[t];
            int take =INT_MIN;
            int rodlength = ind+1;
            if(rodlength<=t)
            {
                take = price[ind] +curr[t-rodlength]; 
            }
           curr[t]=max(take,nottake);
        }
        prev=curr;
    }
    return prev[target];
}

// most space optimised code 
// 1 d array spaceoptimisation 
// tc:o(n*target)
// sc:o(n)
int cutRod(vector<int> &price, int target)
{
    int N =price.size();
    vector<int>prev(target+1,0);
    for(int i=0;i<=target;i++)
    {
       prev[i]=i*price[0];
    }
    for(int ind=1;ind<N;ind++)
    {
        for(int t=0;t<=target;t++)
        {
             int nottake = 0 +prev[t];
            int take =INT_MIN;
            int rodlength = ind+1;
            if(rodlength<=t)
            {
                take = price[ind] +prev[t-rodlength]; 
            }
           prev[t]=max(take,nottake);
        }
    }
    return prev[target];
}
