class Solution {
public:
    // using recursion 
    int f(int i,int j,vector<vector<int>>&matrix)
    {
        if(i>=0 and j>=0 and matrix[i][j]==1)
        {
            return 0;
        }
        if(i==0 and j==0)
        {
            return 1;
        }
        if(i<0 or j<0)
        {
            return 0;
        }
        int up=f(i-1,j,matrix);
        int left=f(i,j-1,matrix);
        return up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        return f(n-1,m-1,obstacleGrid);
    }
    
    // Using Memoisation dp 
    // top down approach 
     int f(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp)
    {
        if(i>=0 and j>=0 and matrix[i][j]==1)
        {
            return 0;
        }
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
        int up=f(i-1,j,matrix,dp);
        int left=f(i,j-1,matrix,dp);
        return dp[i][j]=up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,obstacleGrid,dp);
    }
    
    // Tabulation approach 
    // bottom up 
    // int mod=(int)(1e9+7);
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        int dp[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(obstacleGrid[i][j]==1)
                {
                    dp[i][j]=0;
                }
                else if(i==0 and j==0)
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
                    dp[i][j]= (up+left);
                }
            }
        }
        return dp[n-1][m-1];
    }
    
    // space optimise 
     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<int>prev(n,0);
        for(int i=0;i<n;i++)
        {
            vector<int>curr(m,0);
            for(int j=0;j<m;j++)
            {
                if(obstacleGrid[i][j]==1)
                {
                    curr[j]=0;
                }
                else if(i==0 and j==0)
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
                    curr[j]= (up+left);
                }
            }
            prev=curr;
        }
        return prev[m-1];
    }
};
