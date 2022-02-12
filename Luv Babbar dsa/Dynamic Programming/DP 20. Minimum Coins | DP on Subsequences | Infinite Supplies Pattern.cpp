// Coding Ninja 
// using Recursion 
// tc:>>>>>o(2^n) Exponential
// sc:o(target) 
int f(int ind,int T,vector<int>&nums)
{
    if(ind==0)
    {
        if(T%nums[0]==0)
        {
            return T/nums[0];
        }
        return 1e9;
    }
    
    int nottake= 0+f(ind-1,T,nums);
    int take= INT_MAX;
    if(nums[ind]<=T)
    {
        take = 1+f(ind,T-nums[ind],nums);
    }
    return min(take,nottake);
}

int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
   	int ans= f(n-1,x,num);
    if(ans>=1e9)
    {
        return -1;
    }
    return ans;
}

// // using memoisation 
// // tc:o(n*target)
// // sc:o(n*target) +o(target)
int f(int ind,int T,vector<int>&nums,vector<vector<int>>&dp)
{
    if(ind==0)
    {
        if(T%nums[0]==0)
        {
            return T/nums[0];
        }
        return 1e9;
    }
    if(dp[ind][T]!=-1)
    {
       return dp[ind][T];
    }
    int nottake= 0+f(ind-1,T,nums,dp);
    int take= INT_MAX;
    if(nums[ind]<=T)
    {
        take = 1+f(ind,T-nums[ind],nums,dp);
    }
    return dp[ind][T]= min(take,nottake);
}

int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(x+1,-1));
   	int ans= f(n-1,x,num,dp);
    if(ans>=1e9)
    {
        return -1;
    }
    return ans;
}

// // using Tabulation
// // Bottom up dp 
// // // tc:o(n*target)
// // // sc:o(n*target) 
int minimumElements(vector<int> &nums, int target)
{
    int n=nums.size();
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    for(int T=0;T<=target;T++)
    {
        if(T% nums[0]==0)
        {
            dp[0][T]=T/nums[0];
        }
        else
        {
            dp[0][T]=1e9;
        }
    }
    
    for(int ind=1;ind<n;ind++)
    {
        for(int T=0;T<=target;T++)
        {
            int nottake= 0+dp[ind-1][T];
            int take= INT_MAX;
            if(nums[ind]<=T)
            {
                take = 1+dp[ind][T-nums[ind]];
            }
            dp[ind][T]= min(take,nottake);
        }
    }
    
   	int ans= dp[n-1][target];
    if(ans>=1e9)
    {
        return -1;
    }
    return ans;
}

// using Space optimisation
// Bottom up dp 
// // tc:o(n*target)
// // sc:o(1)
int minimumElements(vector<int> &nums, int target)
{
    int n=nums.size();
    vector<int>prev(target+1,0),curr(target+1,0);
    for(int T=0;T<=target;T++)
    {
        if(T% nums[0]==0)
        {
            prev[T]=T/nums[0];
        }
        else
        {
            prev[T]=1e9;
        }
    }
    
    for(int ind=1;ind<n;ind++)
    {
        for(int T=0;T<=target;T++)
        {
            int nottake= 0+prev[T];
            int take= INT_MAX;
            if(nums[ind]<=T)
            {
                take = 1+curr[T-nums[ind]];
            }
            curr[T]= min(take,nottake);
        }
        prev=curr;
    }
    
   	int ans= prev[target];
    if(ans>=1e9)
    {
        return -1;
    }
    return ans;
}
