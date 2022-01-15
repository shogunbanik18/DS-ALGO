class Solution {
public:
    // recursion 
    // tc : O(n^3)
    // i on left half and n-i-1 of right half 
    // int numTrees(int n) 
    // {
    //     int result=0;
    //     if(n==0 or n==1)
    //     {
    //         return 1;
    //     }
    //     for(int i=0;i<n;i++)
    //     {
    //         result=result+numTrees(i)*numTrees(n-i-1);
    //     }
    //     return result;
    // }
    
    // tc:O(n*2)
    // Dp  memoisation 
     int numTrees(int n) 
    {
        vector<int>dp(n+1,0);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
               dp[i]+=dp[j]*dp[i-j-1]; 
            }
            
        }
        return dp[n];
    }
};

