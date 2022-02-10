int mod =(int)(1e9+7);
// Using Memoisation 
int f(int ind,int sum,vector<int>&num,vector<vector<int>>&dp)
{
    if(ind==0)
    {
        if(sum==0 and num[0]==0)
        {
            return 2;
        }
        if(sum==0 or sum==num[0])
        {
            return 1;
        }
        return 0;
    }
    if(dp[ind][sum]!=-1)
    {
        return dp[ind][sum];
    }
    int nottake =f(ind-1,sum,num,dp);
	int take=0;
	if(num[ind]<=sum)
	{
	    take=f(ind-1,sum-num[ind],num,dp);
	}
	return dp[ind][sum]=(take+nottake)%mod;
}

int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,-1));
    return f(n-1,tar,num,dp);
}


// using tabulation 
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,0));
    if(num[0]==0)
    {
          dp[0][0]=2;
    }
    else
    {
        dp[0][0]=1;
    }
    
    if(num[0]!=0 and num[0]<=tar)
    {
        dp[0][num[0]]=1;
    }
    for(int ind=1;ind<n;ind++)
    {
        for(int sum=0;sum<=tar;sum++)
        {
                int nottake =dp[ind-1][sum];
                int take=0;
                if(num[ind]<=sum)
                {
                    take=dp[ind-1][sum-num[ind]];
                }
                dp[ind][sum]=(take+nottake)%mod;
        }
    }
    return dp[n-1][tar];
}


// using space optimisation 
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<int>prev(tar+1,0),curr(tar+1,0);
    if(num[0]==0)
    {
          prev[0]=2;
    }
    else
    {
        prev[0]=1;
    }
    
    if(num[0]!=0 and num[0]<=tar)
    {
        prev[num[0]]=1;
    }
    for(int ind=1;ind<n;ind++)
    {
        for(int sum=0;sum<=tar;sum++)
        {
                int nottake =prev[sum];
                int take=0;
                if(num[ind]<=sum)
                {
                    take=prev[sum-num[ind]];
                }
                curr[sum]=(take+nottake)%mod;
        }
        prev=curr;
    }
    return prev[tar];
}
int countPartitions(int n, int d, vector<int> &arr) 
{
    int totalsum=0;
   for(auto &it:arr)
   {
       totalsum+=it;
   }
    if(totalsum-d<0 or (totalsum-d)%2!=0)
    {
        return false;
    }
    return findWays(arr,(totalsum-d)/2);
}


