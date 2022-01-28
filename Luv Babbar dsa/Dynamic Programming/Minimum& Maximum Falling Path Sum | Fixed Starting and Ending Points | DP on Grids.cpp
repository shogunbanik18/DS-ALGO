// ;Leetcode for Minimum path sum of variable starting and ending points in a 2d grid  
class Solution {
public:
    // using recursion 
    // tc:(3^N) exponential
    // sc:0(1)
    int f(int i,int j,vector<vector<int>>&matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        if(j<0 or j>=m)
        {
            return 1e9;
        }
        if(i==0)
        {
            return matrix[0][j];
        }
        int up=matrix[i][j]+f(i-1,j,matrix);
        int left=matrix[i][j]+f(i-1,j-1,matrix);
        int right=matrix[i][j]+f(i-1,j+1,matrix);
        return min(up,min(left,right));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        int mini=1e9;
        for(int j=0;j<m;j++)
        {
            mini=min(mini,f(n-1,j,matrix));
        }
        return mini;
    }
    
    
    // using memoisation dp
    // overlapping subproblems 
    // tc:O(n*m)
    // sc:o(n*m)+o(n)stack space + dp vector space
    int f(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        if(j<0 or j>=m)
        {
            return 1e9;
        }
        if(i==0)
        {
            return matrix[0][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int up=matrix[i][j]+f(i-1,j,matrix,dp);
        int left=matrix[i][j]+f(i-1,j-1,matrix,dp);
        int right=matrix[i][j]+f(i-1,j+1,matrix,dp);
        return dp[i][j]=min(up,min(left,right));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        int mini=1e9;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int j=0;j<m;j++)
        {
            mini=min(mini,f(n-1,j,matrix,dp));
        }
        return mini;
    }
    
    
    // using tabulation dp
    // overlapping subproblems 
    // tc:O(n*m)
    // sc:o(n*m)+ dp vector space
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
            dp[0][j]=matrix[0][j];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int up=matrix[i][j]+dp[i-1][j];
                int left=matrix[i][j];
                if(j-1>=0)
                {
                    left+=dp[i-1][j-1];
                }
                else
                {
                    left+=1e8;
                }
                int right=matrix[i][j];
                if(j+1<m)
                {
                    right+=dp[i-1][j+1];
                }
                else
                {
                    right+=1e8;
                }
                dp[i][j]=min(up,min(left,right));
            }
        }
        
        int mini=1e8;
        for(int j=0;j<m;j++)
        {
            mini=min(mini,dp[n-1][j]);
        }
        return mini;  
    }
    
    // Space optimisation 
    // using tabulation dp
    // overlapping subproblems 
    // tc:O(n*m)
    // sc:o(n*m)
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>prev(m,0);
         vector<int>curr(m,0);
        for(int j=0;j<m;j++)
        {
            prev[j]=matrix[0][j];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int up=matrix[i][j]+prev[j];
                int left=matrix[i][j];
                if(j-1>=0)
                {
                    left+=prev[j-1];
                }
                else
                {
                    left+=1e8;
                }
                int right=matrix[i][j];
                if(j+1<m)
                {
                    right+=prev[j+1];
                }
                else
                {
                    right+=1e8;
                }
                curr[j]=min(up,min(left,right));
            }
            prev=curr;
        }
        
        int mini=1e8;
        for(int j=0;j<m;j++)
        {
            mini=min(mini,prev[j]);
        }
        return mini;  
    }
};
