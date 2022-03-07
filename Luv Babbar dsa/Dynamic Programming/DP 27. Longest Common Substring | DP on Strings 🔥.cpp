// Using Tabulation dp 
// tc: o(n*m)
// sc:o(n*m)
int lcs(string &str1, string &str2)
{
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    
    for(int ind2=0;ind2<=m;ind2++)
    {
        dp[0][ind2]=0;
    }
    for(int ind1=0;ind1<=n;ind1++)
    {
        dp[ind1][0]=0;
    }
    int ans=0;
    for(int ind1=1;ind1<=n;ind1++)
    {
        for(int ind2=1;ind2<=m;ind2++)
        {
            if(str1[ind1-1]==str2[ind2-1])
            {
                dp[ind1][ind2]= 1+ dp[ind1-1][ind2-1];
                ans=max(ans,dp[ind1][ind2]);
            }
            else
            {
                dp[ind1][ind2]=0;
            }
        }
    }
    return ans;
}

// using space optimisation dp 
// tc: o(n*m)
// sc:o(n)
int lcs(string &str1, string &str2)
{
    int n=str1.size();
    int m=str2.size();
    vector<int>prev(m+1,0),curr(m+1,0);
    
//     for(int ind2=0;ind2<=m;ind2++)
//     {
//         prev[ind2]=0;
//     }
//     for(int ind1=0;ind1<=n;ind1++)
//     {
//         curr[0]=0;
//     }
    int ans=0;
    for(int ind1=1;ind1<=n;ind1++)
    {
        for(int ind2=1;ind2<=m;ind2++)
        {
            if(str1[ind1-1]==str2[ind2-1])
            {
                curr[ind2]= 1+ prev[ind2-1];
                ans=max(ans,curr[ind2]);
            }
            else
            {
                curr[ind2]=0;
            }
        }
        prev=curr;
    }
    return ans;
}
