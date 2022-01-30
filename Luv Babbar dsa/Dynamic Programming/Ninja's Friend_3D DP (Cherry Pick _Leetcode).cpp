
// // using Recursion 
// // tc: (3^N +3^N)
// // sc:O(1) auxiliary stack space
int f(int i,int j1,int j2,int r,int c,vector<vector<int>> &grid)
{ 
//     outof bound cases 
    if((j1<0 or j1>=c) or (j2<0 or j2>=c))
    {
        return -1e8;
    }
//     destination case 
    if(i==r-1)
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
    
//     explore all possible paths 9 paths here
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
            value+=f(i+1,j1+dj1,j2+dj2,r,c,grid);
            maxi=max(maxi,value);
        }
    }
    return maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) 
{
    return f(0,0,c-1,r,c,grid);
    // Write your code here.
}


// using Memoisation  
// tc: o(N*M*M)
// sc:O(n+m+m)+O(1) auxiliary stack space
int f(int i,int j1,int j2,int r,int c,vector<vector<int>> &grid,
     vector<vector<vector<int>>>&dp)
{ 
//     outof bound cases 
    if((j1<0 or j1>=c) or (j2<0 or j2>=c))
    {
        return -1e8;
    }
//     destination case 
    if(i==r-1)
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
//     explore all possible paths 9 paths here
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
            value+=f(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
            maxi=max(maxi,value);
        }
    }
    return dp[i][j1][j2]=maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) 
{
//     declaring a 3d dp 
//     int dp[n][m][m]
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return f(0,0,c-1,r,c,grid,dp);
    // Write your code here.
}
