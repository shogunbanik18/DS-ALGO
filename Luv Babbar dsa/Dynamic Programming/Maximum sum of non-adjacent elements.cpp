class Solution{
public:	
	// calculate the maximum sum with out adjacent
// 	using recursion 
// tc:O(2^N)
// sc:O(1)
	int f(int ind,int *arr)
	{
	   // base case 
	    if(ind==0)
	    {
	        return arr[0];
	    }
	    
	    if(ind<1)
	    {
	        return 0;
	    }
	    int take=arr[ind]+f(ind-2,arr);
	    int nottake=0+f(ind-1,arr);
	    return max(take,nottake);
	}
	
	int findMaxSum(int *arr, int n) 
	{
	    return f(n-1,arr);
	    // code here
	}

    // using dp
    // memoisation
    // tc:o(n)
    // sc:o(n)+o(n)
    int f(int ind,int *arr,vector<int>&dp)
	{
	   // base case 
	    if(ind==0)
	    {
	        return arr[0];
	    }
	    
	    if(ind<1)
	    {
	        return 0;
	    }
	    
	    if(dp[ind]!=-1)
	    {
	        return dp[ind];
	    }
	    
	    int take=arr[ind]+f(ind-2,arr,dp);
	    int nottake=0+f(ind-1,arr,dp);
	    return dp[ind]=max(take,nottake);
	}
	
	int findMaxSum(int *arr, int n) 
	{
	    vector<int>dp(n+1,-1);
	    return f(n-1,arr,dp);
	    // code here
	}

// tabulation form
// Bottom up dp approach 
// tc:O(n)
// sc:o(n)
	int findMaxSum(int *arr, int n) 
	{
	   // declare the dp array  
	    vector<int>dp(n+1,-1);
	   // convert the base case into array
	   dp[0]=arr[0];
	   int neg=0;
	   for(int i=1;i<n;i++)
	   {
	       int take=arr[i];
	       if(i>1)
	       {
	           take+=dp[i-2];
	       }
	       int nottake=0+dp[i-1];
	       dp[i]=max(take,nottake);
	   }
	   return dp[n-1];
	}

// space optimisation best 
// tc:O(N)
// sc: O(1)
	int findMaxSum(int *arr, int n) 
	{
	    int prev1=arr[0];
	    int prev2=0;
	    for(int i=1;i<n;i++)
	    {
	        int take=arr[i];
	        if(i>1)
	        {
	            take+=prev2;
	        }
	        int nottake=0+prev1;
	        int curri=max(take,nottake);
	        prev2=prev1;
	        prev1=curri;
	    }
	    return prev1;
	}
};
