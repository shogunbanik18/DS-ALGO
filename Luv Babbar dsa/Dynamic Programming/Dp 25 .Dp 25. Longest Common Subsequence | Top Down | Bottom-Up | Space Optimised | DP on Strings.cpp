class Solution {
public:
    // general thinking of 2 pointer approach 
    
//     // using recursion 
//     // tc: o(2^n * 2^n)
//     // sc:o(n) stack space
    int f(int ind1,int ind2,string text1,string text2)
    {
        if(ind1<0 or ind2<0)
        {
            return 0;
        }
        
        if(text1[ind1]==text2[ind2])
        {
            return 1+ f(ind1-1,ind2-1,text1,text2);
        }
        return 0 + max(f(ind1-1,ind2,text1,text2),f(ind1,ind2-1,text1,text2));
    }
    
    int longestCommonSubsequence(string text1, string text2)
    {
        int n=text1.size();
        int m=text2.size();
        return f(n-1,m-1,text1,text2);
    }
    
    // using recursion 
    // tc: o(n*m)
    // sc:o(n*m) + o(n+m) stack space
    int f(int ind1,int ind2,string text1,string text2,vector<vector<int>>&dp)
    {
        if(ind1<0 or ind2<0)
        {
            return 0;
        }
        
        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }
        
        if(text1[ind1]==text2[ind2])
        {
            return 1+ f(ind1-1,ind2-1,text1,text2,dp);
        }
        return dp[ind1][ind2]=0 + max(f(ind1-1,ind2,text1,text2,dp),f(ind1,ind2-1,text1,text2,dp));
    }
    
    int longestCommonSubsequence(string text1, string text2)
    {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,text1,text2,dp);
    }
    
//     // Recursion Shifting of index by right 
    int f(int ind1,int ind2,string text1,string text2,vector<vector<int>>&dp)
    {
        if(ind1==0)
        {
            return 0;
        }
        
        if(ind2==0)
        {
            return 0;
        }
        
        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }
        
        if(text1[ind1-1]==text2[ind2-1])
        {
            return 1+ f(ind1-1,ind2-1,text1,text2,dp);
        }
        return dp[ind1][ind2]=0 + max(f(ind1-1,ind2,text1,text2,dp),f(ind1,ind2-1,text1,text2,dp));
    }
    
    int longestCommonSubsequence(string text1, string text2)
    {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,text1,text2,dp);
    }
    
    
//     // Tabulation 
//     // Bottom up dp 
//     // tc: o(n*m)
//     // sc: o(n*m)    
    int longestCommonSubsequence(string text1, string text2)
    {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int ind2=0;ind2<=m;ind2++)
        {
            dp[0][ind2]=0;
        }
        
         for(int ind1=0;ind1<=n;ind1++)
        {
            dp[ind1][0]=0;
        }
        
        for(int ind1=1;ind1<=n;ind1++)
        {
            for(int ind2=1;ind2<=m;ind2++)
            {
                if(text1[ind1-1]==text2[ind2-1])
                {
                    dp[ind1][ind2]=1+ dp[ind1-1][ind2-1];
                }
                else
                {
                    dp[ind1][ind2]=0+ max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
            }
        }
        
        return dp[n][m];
    }
    
    // Tabulation  (Space Optimisation)
    // Bottom up dp 
    // tc: o(n*m)
    // sc: o(n+m)    
    int longestCommonSubsequence(string text1, string text2)
    {
        int n=text1.size();
        int m=text2.size();
        vector<int>prev(m+1,0),curr(m+1,0);
        
        for(int ind2=0;ind2<=m;ind2++)
        {
            prev[ind2]=0;
        }
        
        //  for(int ind1=0;ind1<=n;ind1++)
        // {
        //     dp[ind1][0]=0;
        // }
        
        for(int ind1=1;ind1<=n;ind1++)
        {
            for(int ind2=1;ind2<=m;ind2++)
            {
                if(text1[ind1-1]==text2[ind2-1])
                {
                    curr[ind2]=1+ prev[ind2-1];
                }
                else
                {
                     curr[ind2]=0+ max(prev[ind2],curr[ind2-1]);
                }
            }
            prev=curr;
        }
        
        return prev[m];
    }
};
