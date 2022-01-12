// tc :O(2^N)
// sc:O(N)
int f(int ind,vector<int>&nums)
{
    if(ind==0)
    {
        return nums[ind];
    }
    if(ind<1)
    {
        return 0;
    }
    
    int pick =nums[ind]+f(ind-2,nums);
    int notpick=0+f(ind-1,nums);
    return max(pick,notpick);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n=nums.size();
    return f(n-1,nums);
    // Write your code here.
}

// tc :O(N)
// sc:O(N)+O(N)
// using dp Memoisation 
int f(int ind,vector<int>&nums,vector<int>&dp)
{
    if(ind==0)
    {
        return nums[ind];
    }
    if(ind<1)
    {
        return 0;
    }
    if(dp[ind]!=-1)
    {
        return dp[ind];
    }
    
    int pick =nums[ind]+f(ind-2,nums,dp);
    int notpick=0+f(ind-1,nums,dp);
    return dp[ind]=max(pick,notpick);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n=nums.size();
    vector<int>dp(n,-1);
    return f(n-1,nums,dp);
    // Write your code here.
}

// Tabular method 
// space optimization 
// tc:o(N)
// sc:O(N)
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n=nums.size();
    vector<int>dp(n,-1);
//     return f(n-1,nums,dp);
    dp[0]=nums[0];
    int neg=0;
    for(int i=1;i<n;i++)
    {
        int take=nums[i];
        if(i>1)
        {
            take+=dp[n-2];
        }
        int nottake=0+dp[i-1];
        dp[i]=max(take,nottake);
    }
    return dp[n-1];
    // Write your code here.
}

// space optimization Tabular Method 
// tc:o(N)
// sc:O(1)
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n=nums.size();
    int prev1=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++)
    {
        int take=nums[i];
        if(i>1)
        {
            take+=prev2;
        }
        int nottake=0+prev1;
        
        int curri=max(take,nottake);
        prev2=prev1;
        prev1=curri;
    }
    return prev1;;
    // Write your code here.
}
