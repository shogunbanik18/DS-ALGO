
class Solution
{
public:
        
    long long count(string a ,string b)
    {
        // base case 
        long long n = a.size();
        long long m = b.size();
        
        // vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
        long long dp[n + 1][m+ 1] ;
        
        for(long long i=0;i<=n;i++)
        {
            for(long long j=0;j<=m;j++)
            {
                dp[i][j] = 0;
            }
        }
        
        for(long long j=0;j<=m;j++)
        {
            dp[0][j] = 0;
        }
        
        for(long long i=0;i<=n;i++)
        {
            dp[i][0] = 1;
        }
        
        for(long long i=1;i<=n;i++)
        {
            for(long long j=1;j<=m;j++)
            {
                if(a[i-1] == b[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }

                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][m];
    }
    
    long long numberOfWays(string s) 
    {
        string s1 = "101";
        string s2 = "010";
        return count(s,s1) + count(s,s2);
    }
};
