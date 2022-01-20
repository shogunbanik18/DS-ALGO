class Solution {
public:
  
//   most optimalsolution at the end 
    // using recursion 
    // tc : 2^(m*n)
    // sc: path length o((n-1)+(m-1))
    int f(int i,int j)
    {
        // like atleast one path is present there 
        if(i==0 and j==0)
        {
            return 1;
        }
        if(i<0 or j<0)
        {
            return 0;
        }
        int up=f(i-1,j);
        int left=f(i,j-1);
        return up+left;
    }
    
    int uniquePaths(int m, int n) 
    {
        return f(m-1,n-1);
    }
    
    // using memoisation dynamic programming 
    // tc: o(M*N)
    // sc: o((n-1)+(m-1)) +o(n*m)
    int f(int i,int j,vector<vector<int>>&dp)
    {
        // like atleast one path is present there 
        if(i==0 and j==0)
        {
            return 1;
        }
        if(i<0 or j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int up=f(i-1,j,dp);
        int left=f(i,j-1,dp);
        return dp[i][j]=up+left;
    }
    
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp);
    }
    
    // tabulation using dp
    // Bottom up dp 
    // tc: o(M*N)
    // sc: o((n-1)+(m-1)) +o(n*m)
     int uniquePaths(int m, int n) 
    {
        int dp[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 and j==0)
                {
                    dp[i][j]=1;
                }
                else
                {
                    int up=0;
                    int left=0;
                    if(i>0)
                    {
                        up=dp[i-1][j];
                    }
                    if(j>0)
                    {
                        left=dp[i][j-1];
                    }
                    dp[i][j]=up+left;
                }
                
            }
        }
        return dp[m-1][n-1];
    }
    
    
    // space optimisation 
    int uniquePaths(int m, int n) 
    {
        vector<int>prev(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int>curr(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 and j==0)
                {
                    curr[j]=1;
                }
                else
                {
                    int up=0;
                    int left=0;
                    if(i>0)
                    {
                        up=prev[j];
                    }
                    if(j>0)
                    {
                        left=curr[j-1];
                    }
                    curr[j]=up+left;
                }   
            }
            prev=curr;
        }
        return prev[n-1];
    }
    
    // using striver sheet approach 
     // tc : 2^(m*n)
    // sc: stack space 
    int count(int i,int j,int n,int m)
    {
        if(i==(n-1) and j==(m-1))
        {
            return 1;
        }
        if(i>=n or j>=n)
        {
            return 0;
        }
        else return count(i+1,j)+count(i,j+1);
    }
    
    // using dp
    // memoisation
    // tc :O(n*m)
    // sc:o(n*m)
    int count(int i,int j,int n,int m,vector<vector<int>>&dp)
    {
        if(i==(n-1) and j==(m-1))
        {
            return 1;
        }
        if(i>=n or j>=n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        else return dp[i][j]=count(i+1,j,dp)+count(i,j+1,dp);
    }
    
    // most optimal solution 
    // can be done by combinatrix method
    // tc: o(m-1) or o(n-1)
    // sc:o(1)
    int uniquePaths(int m, int n) 
    {
        int N=n+m-2;
        int r=m-1;
        double res=1;
        for(int i=1;i<=r;i++)
        {
            res=res*(N-r+i)/i;
        }
        return (int)res;
    }
};
