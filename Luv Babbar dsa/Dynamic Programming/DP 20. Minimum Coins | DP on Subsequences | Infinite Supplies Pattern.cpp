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
        }a
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


// Leetcode
class Solution {
public:
    // Greedy does not works due to uniformity
    // eg [9,6,5,1] min coins can be 2 but our ans gives 3
    
//     // using recursion 
//     // tc: exponential 
//     // sc: auxiliary stack space
//     int f(int ind,int target,vector<int>&arr)
//     {
//         if(ind==0)
//         {
//             if(target%arr[0]==0)
//             {
//                 return target/arr[0];
//             }
//             else
//             {
//                 return 1e9;
//             }
//         }
//         int nottake = 0 +f(ind-1,target,arr);
//         int take=1e9;
//         if(arr[ind]<=target)
//         {
//             take = 1+ f(ind,target-arr[ind],arr);
//         }
//         return min(take,nottake);
//     }
    
//     int coinChange(vector<int>& coins, int amount) 
//     {
//         int n=coins.size();
//         int ans= f(n-1,amount,coins);
//         if(ans>=1e9)
//         {
//             return -1;
//         }
//         return ans;
//     }
    
    
    // using Memoisation
   // tc: o(n*target)
    // sc: o(n*target) + o(n) auxiliary stack space
//     int f(int ind,int target,vector<int>&arr,vector<vector<int>>&dp)
//     {
//         if(ind==0)
//         {
//             if(target%arr[0]==0)
//             {
//                 return target/arr[0];
//             }
//             else
//             {
//                 return 1e9;
//             }
//         }
//         if(dp[ind][target]!=-1)
//         {
//             return dp[ind][target];
//         }
//         int nottake = 0 +f(ind-1,target,arr,dp);
//         int take=1e9;
//         if(arr[ind]<=target)
//         {
//             take = 1+ f(ind,target-arr[ind],arr,dp);
//         }
//         return dp[ind][target]= min(take,nottake);
//     }
    
//     int coinChange(vector<int>& coins, int amount) 
//     {
//         int n=coins.size();
//         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
//         int ans= f(n-1,amount,coins,dp);
//         if(ans>=1e9)
//         {
//             return -1;
//         }
//         return ans;
//     }
    
//     // using Tabulation
//     // tc: o(n*target)
//     // sc: o(n*target)
//     int coinChange(vector<int>& coins, int amount) 
//     {
//         int n=coins.size();
//         vector<vector<int>>dp(n,vector<int>(amount+1,0));
        
//         for(int i=0;i<=amount;i++)
//         {
//             if(i%coins[0]==0)
//             {
//                 dp[0][i]=i/coins[0];
//             }
//             else
//             {
//                 dp[0][i]=1e9;
//             }
//         }
        
//         for(int ind=1;ind<n;ind++)
//         {
//             for(int target=0;target<=amount;target++)
//             {
//                 int nottake = 0 +dp[ind-1][target];
//                 int take=1e9;
//                 if(coins[ind]<=target)
//                 {
//                     take = 1+ dp[ind][target-coins[ind]];
//                 }
//                 dp[ind][target]= min(take,nottake);
//             }
//         }
        
//         int ans= dp[n-1][amount];
//         if(ans>=1e9)
//         {
//             return -1;
//         }
//         return ans;
//     }
    
    // using Tabulation space optimisation
    // tc: o(n*target)
    // sc: o(n)
    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        vector<int>prev(amount+1,0),curr(amount+1,0);
        
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
            {
                prev[i]=i/coins[0];
            }
            else
            {
                prev[i]=1e9;
            }
        }
        
        for(int ind=1;ind<n;ind++)
        {
            for(int target=0;target<=amount;target++)
            {
                int nottake = 0 + prev[target];
                int take=1e9;
                if(coins[ind]<=target)
                {
                    take = 1+ curr[target-coins[ind]];
                }
                curr[target]= min(take,nottake);
            }
            prev=curr;
        }
        
        int ans= prev[amount];
        if(ans>=1e9)
        {
            return -1;
        }
        return ans;
    }
};
