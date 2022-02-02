class Solution {
public:
// Greedy can't be used due to uniformity 
//     // using recursion
//     // tc: 3^n * 3^n
//     // sc:o(n) stack space 
    int f(int i,int j1,int j2,int n,int m,vector<vector<int>>&grid)
    {
        // our of bound cases 
        if(j1<0 or j2<0 or j1>=m or j2>=m)
        {
            return -1e8;
        }
        if(i==n-1)
        {
            if(j1==j2)
            {
                return grid[i][j1];    
            }
            else
            {
                return grid[i][j1]+grid[i][j2];
            }
        }
        // explore all the possible paths 
        int maxi=-1e8;
        for(int dj1=-1;dj1<=1;dj1++)
        {
            for(int dj2=-1;dj2<=1;dj2++)
            {
                int value=0;
                if(j1==j2)
                {
                    value+=grid[i][j1];
                }
                else
                {
                    value+=grid[i][j1]+grid[i][j2];
                }
                value+=f(i+1,j1+dj1,j2+dj2,n,m,grid);
                maxi=max(maxi,value);
            }
        }
        return maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        return f(0,0,m-1,n,m,grid);
    }
    
    
    // using memoisation 
    // top down dp 
    // overlapping subproblems 
    // tc:o(n*m*m)
    // sc:o(n)+o(n*m*m) stack space 
    int f(int i,int j1,int j2,int n,int m,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp)
    {
        // our of bound cases 
        if(j1<0 or j2<0 or j1>=m or j2>=m)
        {
            return -1e8;
        }
        if(i==n-1)
        {
            if(j1==j2)
            {
                return grid[i][j1];    
            }
            else
            {
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1)
        {
            return dp[i][j1][j2];
        }
        // explore all the possible paths 
        int maxi=-1e8;
        for(int dj1=-1;dj1<=1;dj1++)
        {
            for(int dj2=-1;dj2<=1;dj2++)
            {
                int value=0;
                if(j1==j2)
                {
                    value+=grid[i][j1];
                }
                else
                {
                    value+=grid[i][j1]+grid[i][j2];
                }
                value+=f(i+1,j1+dj1,j2+dj2,n,m,grid,dp);
                maxi=max(maxi,value);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0,m-1,n,m,grid,dp);
    }
    
    
//         // Tabulation Approach 
//         // Bottom up dp
//         // tc:O(n*m*m)
//         // sc:o(n*m*m)
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        // base case in terms of loop 
         for(int j1=0;j1<m;j1++)
         {
             for(int j2=0;j2<m;j2++)
             {
                 if(j1==j2)
                 {
                     dp[n-1][j1][j2]=grid[n-1][j1];
                 }
                 else
                 {
                     dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
                 }
             }
         }
         
         // exploring all the path in terms of loops 
         for(int i=n-2;i>=0;i--)
         {
             for(int j1=0;j1<m;j1++)
             {
                 for(int j2=0;j2<m;j2++)
                 {
                        int maxi=-1e8;
                        for(int dj1=-1;dj1<=1;dj1++)
                        {
                            for(int dj2=-1;dj2<=1;dj2++)
                            {
                                int value=0;
                                if(j1==j2)
                                {
                                    value+=grid[i][j1];
                                }
                                else
                                {
                                    value+=grid[i][j1]+grid[i][j2];
                                }
                                 if(j1+dj1>=0 and j1+dj1<m and j2+dj2>=0 
                                    and j2+dj2<m)
                                 {
                                      value+=dp[i+1][j1+dj1][j2+dj2];
                                 }
                                else
                                {
                                    value+=-1e8;
                                }
                                maxi=max(maxi,value);
                            }
                        }
                    dp[i][j1][j2]=maxi;
                 }
             }
         }
        return dp[0][0][m-1];
    }
    
    
        // Space optimisation Approach 
        // Bottom up dp
        // tc:O(n*m*m)
        // sc:o(m*m)
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>front(m,vector<int>(m,0));
        vector<vector<int>>curr(m,vector<int>(m,0));
         for(int j1=0;j1<m;j1++)
         {
             for(int j2=0;j2<m;j2++)
             {
                 if(j1==j2)
                 {
                     front[j1][j2]=grid[n-1][j1];
                 }
                 else
                 {
                     front[j1][j2]=grid[n-1][j1]+grid[n-1][j2];
                 }
             }
         }
         
         // exploring all the path in terms of loops 
         for(int i=n-2;i>=0;i--)
         {
             for(int j1=0;j1<m;j1++)
             {
                 for(int j2=0;j2<m;j2++)
                 {
                        int maxi=-1e8;
                        for(int dj1=-1;dj1<=1;dj1++)
                        {
                            for(int dj2=-1;dj2<=1;dj2++)
                            {
                                int value=0;
                                if(j1==j2)
                                {
                                    value+=grid[i][j1];
                                }
                                else
                                {
                                    value+=grid[i][j1]+grid[i][j2];
                                }
                                 if(j1+dj1>=0 and j1+dj1<m and j2+dj2>=0 
                                    and j2+dj2<m)
                                 {
                                      value+=front[j1+dj1][j2+dj2];
                                 }
                                else
                                {
                                    value+=-1e8;
                                }
                                maxi=max(maxi,value);
                            }
                        }
                    curr[j1][j2]=maxi;
                 }
             }
             front=curr;
         }
        return front[0][m-1];
    }
};
