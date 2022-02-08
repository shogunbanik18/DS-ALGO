// // using recusrion approach 
// // tc:o(2^n)
// // sc:o(n) //Auxiliary stack space
int f(int ind,int sum,vector<int>&num)
{
    if(sum==0)
    {
        return 1;
    }
    if(ind==0)
    {
        return (num[0]==sum);
    }
    int nottake =f(ind-1,sum,num);
	int take=0;
	if(num[ind]<=sum)
	{
	    take=f(ind-1,sum-num[ind],num);
	}
	return take+nottake;
}
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    return f(n-1,tar,num);
}


// // using Memoisation approach
// // Top down dp 
// // tc:o(n*target)
// // sc:o(n*target)+o(n) //Auxiliary stack space
int f(int ind,int sum,vector<int>&num,vector<vector<int>>&dp)
{
    if(sum==0)
    {
        return 1;
    }
    if(ind==0)
    {
        return (num[0]==sum);
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
	return dp[ind][sum]=take+nottake;
}
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,-1));
    return f(n-1,tar,num,dp);
}


// // using Tabulation approach
// // Bottom up dp 
// // tc:o(n*target)
// // sc:o(n*target)
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,0));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }
    if(num[0]<=tar)
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
                dp[ind][sum]=take+nottake;
        }
    }
    return dp[n-1][tar];
}


// using Space Optimisation approach
// tc:o(n*target)
// sc:o(1)
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<int>prev(tar+1,0),curr(tar+1,0);
    prev[0]=1,curr[0]=1;
    if(num[0]<=tar)
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
                curr[sum]=take+nottake;
        }
        prev=curr;
    }
    return prev[tar];
}
