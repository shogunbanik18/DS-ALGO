// Using space optimisation 
// tc: o(n*target)+o(n/2)
// sc: o(n*target)
int minSubsetSumDifference(vector<int>& arr, int n)
{
        int totalsum=0;
        for(int i=0;i<arr.size();i++)
        {
            totalsum+=arr[i];
        }
        
    int k=totalsum;
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=true;
    }
    dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++)
    {
        for(int target=1;target<=k;target++)
        {
             bool nottake=dp[ind-1][target];
            bool take=false;
            if(target>=arr[ind])
            {
                take=dp[ind-1][target-arr[ind]];
            }
           dp[ind][target]=(take|nottake);
        }
    }
//     return dp[n-1][k];
     int mini=1e9;
        for(int s1=0;s1<=totalsum/2;s1++)
        {
            if(dp[n-1][s1]==true)
            {
                mini=min(mini,abs((totalsum-s1)-s1));
            }
        }
        return mini;
	// Write your code here.
}

// Using space optimisation 
// tc: o(n*target)+o(n/2)
// sc:o(1)
int minSubsetSumDifference(vector<int>& arr, int n)
{
        int totalsum=0;
        for(int i=0;i<arr.size();i++)
        {
            totalsum+=arr[i];
        }
        
    int k=totalsum;
   	vector<bool>prev(k+1,0),curr(k+1,0);
    prev[0]=curr[0]=true;
    prev[arr[0]]=true;
    for(int ind=1;ind<n;ind++)
    {
        for(int target=1;target<=k;target++)
        {
             bool nottake=prev[target];
            bool take=false;
            if(target>=arr[ind])
            {
                take=prev[target-arr[ind]];
            }
           curr[target]=(take|nottake);
        }
        prev=curr;
    }
//     return dp[n-1][k];
     int mini=1e9;
        for(int s1=0;s1<=totalsum/2;s1++)
        {
            if(prev[s1]==true)
            {
                mini=min(mini,abs((totalsum-s1)-s1));
            }
        }
        return mini;
	// Write your code here.
}
