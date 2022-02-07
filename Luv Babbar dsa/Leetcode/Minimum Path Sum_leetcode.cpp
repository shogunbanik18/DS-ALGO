class Solution {
public:
    // using brute force 
    // recursion 
    // tc :2^n
    // sc:o(1)
    int f(int i,int j,vector<vector<int>>&grid)
    {
        if(i==0 and j==0)
        {
            return grid[i][j]; 
        }
        if(i<0 or j<0)
        {
            return 1e8;
        }
        int up =grid[i][j]+f(i-1,j,grid);
        int left=grid[i][j]+f(i,j-1,grid);
        return min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        return f(n-1,m-1,grid);
    }
    
    // using Top Down Dp 
    // Memoisation
    // tc :o(n)
    // sc:o(n) stack space 
    int f(int i,int j,vector<vector<int>>&grid, vector<vector<int>>&dp)
    {
        if(i==0 and j==0)
        {
            return grid[i][j]; 
        }
        if(i<0 or j<0)
        {
            return 1e8;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int up =grid[i][j]+f(i-1,j,grid,dp);
        int left=grid[i][j]+f(i,j-1,grid,dp);
        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,grid,dp);
    }
    
    // using Bottom up Dp 
    // Tabulation
    // tc :o(n)
    // sc:o(1) 
     int minPathSum(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
         
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 if(i==0 and j==0)
                 {
                    dp[i][j]=grid[i][j];
                 }
                 else
                 {
                   
                    int up=grid[i][j];
                    if(i>0)
                    {
                        up+=dp[i-1][j];
                    }
                    else
                    {
                        up+=1e9;
                    }
                    
                    int left=grid[i][j];
                    if(j>0)
                    {
                        left+=dp[i][j-1];
                    }
                    else
                    {
                        left+=1e9;
                    }
                    
                    
                    dp[i][j]=min(up,left);
                 }
            }
        }
         return dp[n-1][m-1];
    }
    
    
     // using Bottom up Dp 
    // Space optimised
    // tc :o(n)
    // sc:o(1)
     int minPathSum(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>prev(m,0);
         
        for(int i=0;i<n;i++)
        {
            vector<int>curr(m,0);
            for(int j=0;j<m;j++)
            {
                 if(i==0 and j==0)
                 {
                    curr[j]=grid[i][j];
                 }
                 else
                 {
                   
                    int up=grid[i][j];
                    if(i>0)
                    {
                        up+=prev[j];
                    }
                    else
                    {
                        up+=1e9;
                    }
                    
                    int left=grid[i][j];
                    if(j>0)
                    {
                        left+=curr[j-1];
                    }
                    else
                    {
                        left+=1e9;
                    }
                    
                    curr[j]=min(up,left);
                 }
            }
            prev=curr;
        }
         return prev[m-1];
    }
};
