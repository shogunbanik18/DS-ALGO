class Solution{
public:

    // using Recursion
    // tc: Exponential
    // sc:o(1)
    int f(int i,int j,int *arr)
    {
        if(i==j)
        {
            return 0;
        }
        int mini=1e9;
        for(int k=i;k<j;k++)
        {
            int steps= arr[i-1]*arr[k]*arr[j] + f(i,k,arr)+f(k+1,j,arr);
            // mini=min(mini,steps);
            if(steps<mini)
            {
                mini=steps;
            }
        }
        return mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        return f(1,N-1,arr);
    }
    
    
    // // using memosiation  dp 
    // // top down dp 
    // // tc: o(n*n)*n
    // // sc:o(n^2)+o(n) stack space
    
    int f(int i,int j,int *arr,vector<vector<int>>&dp)
    {
        if(i==j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int mini=1e9;
        for(int k=i;k<j;k++)
        {
            int steps= arr[i-1]*arr[k]*arr[j] + f(i,k,arr,dp)+f(k+1,j,arr,dp);
            // mini=min(mini,steps);
            if(steps<mini)
            {
                mini=steps;
            }
        }
        return dp[i][j]=mini;
    }

    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(N,vector<int>(N,-1));
        return f(1,N-1,arr,dp);
    }
    
    
    // using Tabulation dp 
    // Bottom up dp 
    // tc: o(n*n)*n
    // sc:o(n^2)
    int f(int i,int j,int *arr,vector<vector<int>>&dp)
    {
        if(i==j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int mini=1e9;
        for(int k=i;k<j;k++)
        {
            int steps= arr[i-1]*arr[k]*arr[j] + f(i,k,arr,dp)+f(k+1,j,arr,dp);
            // mini=min(mini,steps);
            if(steps<mini)
            {
                mini=steps;
            }
        }
        return dp[i][j]=mini;
    }

    int matrixMultiplication(int N, int arr[])
    {
        int dp[N][N];
        for(int i=1;i<N;i++)
        {
            dp[i][i]=0;
        }
        
        for(int i=N-1;i>=1;i--)
        {
            for(int j=i+1;j<N;j++)
            {
                int mini=1e9;
                for(int k=i;k<j;k++)
                {
                    int steps= arr[i-1]*arr[k]*arr[j] + dp[i][k]+dp[k+1][j];
                    if(steps<mini)
                    {
                        mini=steps;
                    }
                    dp[i][j]=mini;
                }
            }
        }
        return dp[1][N-1];  
    }
};
