// Optimal Solution 
// tc:O(amount)
// // sc:O(1)
int findMinimumCoins(int amount) 
{
    int coins[]={1,2,5,10,20,50,100,500,1000};
    int mincoins=0;
    int n=9;
    
    for(int i=n-1;i>=0;i--)
    {
       if(amount-coins[i]>=0)
       {
           while(amount-coins[i]>=0)
           {   
           		amount=amount-coins[i];
//            		ans.push_back(coins[i]);
               mincoins++;
       		}
    	}
        if(amount==0)
        {
            break;
        }
    }
       return mincoins;
    // Write your code here
}

// // tc:O(amount)
// // sc:O(1)+O(N)
int findMinimumCoins(int amount) 
{
    int coins[]={1,2,5,10,20,50,100,500,1000};
    int n=9;
    vector<int>ans;
    
    for(int i=n-1;i>=0;i--)
    {
        while(amount>=coins[i])
           {   
           		amount=amount-coins[i];
           		ans.push_back(coins[i]);
       		}
    }
    return ans.size();
    // Write your code here
}


// Gfg 
// using dp 

class Solution{
	public:
	
// 	using Greedy Algorithm 
// 	int minCoins(int coins[], int M, int V) 
// 	{ 
// 	    sort(coins,coins+M);
// 	    vector<int>ans;
// 	    for(int i=M-1;i>=0;i--)
// 	    {
// 	        while(V>=coins[i])
// 	        {
// 	            V-=coins[i];
// 	            ans.push_back(coins[i]);
// 	        }
// 	    }
// 	   // for(int i=0;i<ans.size();i++)
// 	   // {
// 	   //     cout<<ans[i]<<" ";
// 	   // }
// 	    int count=ans.size();
// 	    return count;
// 	} 
	
	
// 	// using recursion 
// // 	tc:>>>>>> o(2^n) Exponential generally
// // sc: >>>>>> o(target)
	int f(int ind,int T,int *coins)
	{
	    if(ind==0)
	    {
	        if(T%coins[0]==0)
	        {
	            return T/coins[0];
	        }
	        else
	        {
	            return 1e9;
	        }
	    }
	    int nottake = 0 +f(ind-1,T,coins);
	    int take =1e9;
	    if(coins[ind]<=T)
	    {
	        take = 1+ f(ind,T-coins[ind],coins);
	    }
	    return min(take,nottake);
	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    return f(M-1,V,coins);   	
	} 
	  
	  
// // using Memoisation 
// // 	tc:o(n*target)
// // sc: o(n*target)+o(target)
	int f(int ind,int T,int *coins,vector<vector<int>>&dp)
	{
	    if(ind==0)
	    {
	        if(T%coins[0]==0)
	        {
	            return T/coins[0];
	        }
	        else
	        {
	            return 1e9;
	        }
	    }
	    if(dp[ind][T]!=-1)
	    {
	        return  dp[ind][T];
	    }
	    int nottake = 0 +f(ind-1,T,coins,dp);
	    int take =INT_MAX;
	    if(coins[ind]<=T)
	    {
	        take = 1+ f(ind,T-coins[ind],coins,dp);
	    }
	    return dp[ind][T]=min(take,nottake);
	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>>dp(M,vector<int>(V+1,-1));
	    int ans=f(M-1,V,coins,dp);
	    if(ans>=1e9)
	    {
	        return -1;
	    }
	    return ans;
	} 

// // using Tabulation
// // Bottom up dp 
// // 	tc:o(n*target)
// // sc: o(n*target)
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>>dp(M,vector<int>(V+1,0));
	    for(int T=0;T<=V;T++)
	    {
	        if(T%coins[0]==0)
	        {
	            dp[0][T]= T/coins[0];
	        }
	        else
	        {
	            dp[0][T]= 1e9;
	        }
	    }
	    
	    for(int ind=1;ind<M;ind++)
	    {
	        for(int T=0;T<=V;T++)
	        {
	            int nottake = 0 +dp[ind-1][T];
        	    int take =INT_MAX;
        	    if(coins[ind]<=T)
        	    {
        	        take = 1+ dp[ind][T-coins[ind]];
        	    }
        	    dp[ind][T]=min(take,nottake);
	        }
	    }
	    
	    int ans=dp[M-1][V];
	    if(ans>=1e9)
	    {
	        return -1;
	    }
	    return ans;
	} 

// using Space Optimisation
// Bottom up dp 
// 	tc:o(n*target)
// sc: o(n)
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<int>prev(V+1,0),curr(V+1,0);
	    for(int T=0;T<=V;T++)
	    {
	        if(T%coins[0]==0)
	        {
	            prev[T]= T/coins[0];
	        }
	        else
	        {
	            prev[T]= 1e9;
	        }
	    }
	    
	    for(int ind=1;ind<M;ind++)
	    {
	        for(int T=0;T<=V;T++)
	        {
	            int nottake = 0 +prev[T];
        	    int take =INT_MAX;
        	    if(coins[ind]<=T)
        	    {
        	        take = 1+ curr[T-coins[ind]];
        	    }
        	    curr[T]=min(take,nottake);
	        }
	        prev=curr;
	    }
	    
	    int ans=prev[V];
	    if(ans>=1e9)
	    {
	        return -1;
	    }
	    return ans;
	} 	
	  
};

