// // using recursion 
// // tc: Exponential 
// // sc : o(1) 

// class Solution {
// public:
    
//     bool f(int i,int j, string s1,string s2)
//     {
//         // base case 
//         if(i<0 and j<0)
//         {
//             return true;
//         }
        
//         if(i<0 and j>=0)
//         {
//             return false;
//         }
        
//         if(i>=0 and j<0)
//         {
//             for(int check=0;check<=i;check++)
//             {
//                 if(s1[check]!='*')
//                 {
//                     return false;
//                 }
//             }
//             return true;
//         }
        
//         if(s1[i] == s2[j] or s1[i]=='?')
//         {
//             return f(i-1,j-1,s1,s2);
//         }
        
//         if(s1[i]=='*')
//         {
//             return f(i-1,j,s1,s2) or f(i,j-1,s1,s2);
//         }
        
//         return false;
//     }
    
//     bool isMatch(string s, string p)
//     {
//         string s1 =p;
//         string s2 =s;
//         int n = s1.size();
//         int m = s2.size();
//         return f(n-1,m-1,s1,s2);        
//     }
// };


// // using recursion + Memosiation 
// // tc : o(n*m)
// // sc : o(n*m) + o(n+m) 
// class Solution {
// public:
    
//     bool f(int i,int j, string s1,string s2,vector<vector<int>>&dp)
//     {
//         // base case 
//         if(i<0 and j<0)
//         {
//             return true;
//         }
        
//         if(i<0 and j>=0)
//         {
//             return false;
//         }
        
//         if(i>=0 and j<0)
//         {
//             for(int check=0;check<=i;check++)
//             {
//                 if(s1[check]!='*')
//                 {
//                     return false;
//                 }
//             }
//             return true;
//         }
        
//         if(dp[i][j] !=-1)
//         {
//             return dp[i][j];
//         }
        
//         if(s1[i] == s2[j] or s1[i]=='?')
//         {
//             return dp[i][j] = f(i-1,j-1,s1,s2,dp);
//         }
        
//         if(s1[i]=='*')
//         {
//             return dp[i][j] = f(i-1,j,s1,s2,dp) or f(i,j-1,s1,s2,dp);
//         }
        
//         return dp[i][j] = false;
//     }
    
//     bool isMatch(string s, string p)
//     {
//         string s1 =p;
//         string s2 =s;
//         int n = s1.size();
//         int m = s2.size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return f(n-1,m-1,s1,s2,dp);        
//     }
// };


// / using recursion + Memosiation + conversion to 1 based indexing 
// tc : o(n*m)
// sc : o(n*m) + o(n+m) 
// class Solution {
// public:
    
//     bool f(int i,int j, string s1,string s2,vector<vector<int>>&dp)
//     {
//         // base case 
//         if(i==0 and j==0)
//         {
//             return true;
//         }
        
//         if(i==0 and j>0)
//         {
//             return false;
//         }
        
//         if(i>0 and j==0)
//         {
//             for(int check=1;check<=i;check++)
//             {
//                 if(s1[check-1]!='*')
//                 {
//                     return false;
//                 }
//             }
//             return true;
//         }
        
//         if(dp[i][j] !=-1)
//         {
//             return dp[i][j];
//         }
        
//         if(s1[i-1] == s2[j-1] or s1[i-1]=='?')
//         {
//             return dp[i][j] = f(i-1,j-1,s1,s2,dp);
//         }
        
//         if(s1[i-1]=='*')
//         {
//             return dp[i][j] = f(i-1,j,s1,s2,dp) or f(i,j-1,s1,s2,dp);
//         }
        
//         return dp[i][j] = false;
//     }
    
//     bool isMatch(string s, string p)
//     {
//         string s1 =p;
//         string s2 =s;
//         int n = s1.size();
//         int m = s2.size();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//         return f(n,m,s1,s2,dp);        
//     }
// };


// // / using Tabulation dp
// // tc : o(n*m)
// // // sc : o(n*m) 
// class Solution {
// public:
//     bool isMatch(string s, string p)
//     {
//         string s1 =p;
//         string s2 =s;
//         int n = s1.size();
//         int m = s2.size();
//         vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        
//         // base cases 
//         dp[0][0] = true;
        
//         for(int j=1;j<=m;j++)
//         {
//             dp[0][j] = false;
//         }
        
//         for(int i =1 ;i<=n;i++)
//         {
//             bool flag =true;
//             for(int check=1;check<=i;check++)
//             {
//                 if(s1[check-1]!='*')
//                 {
//                     flag = false;
//                     break;
//                 }
//             }
//             dp[i][0] = flag;
//         }
        
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=m;j++)
//             {
//                 if(s1[i-1] == s2[j-1] or s1[i-1]=='?')
//                 {
//                     dp[i][j] = dp[i-1][j-1];
//                 }

//                 else if(s1[i-1]=='*')
//                 {
//                     dp[i][j] = dp[i-1][j] or dp[i][j-1];
//                 }

//                 else
//                 {
//                     dp[i][j] = false;
//                 }
//             }
//         }
        
//         // printing the dp table 
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=m;j++)
//             {
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         return dp[n][m];        
//     }
// };



// using Tabulation dp space optimisation 
// tc : o(n*m)
// sc : o(n+m) 
class Solution {
public:
    bool isMatch(string s, string p)
    {
        string s1 =p;
        string s2 =s;
        int n = s1.size();
        int m = s2.size();
        vector<bool>prev(m+1,false),curr(m+1,false);
        
        // base cases 
        prev[0] = true;
        
        for(int j=1;j<=m;j++)
        {
            prev[j] = false;
        }
         
        for(int i=1;i<=n;i++)
        {
            bool flag =true;
            for(int check=1;check<=i;check++)
            {
                if(s1[check-1]!='*')
                {
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1] == s2[j-1] or s1[i-1]=='?')
                {
                    curr[j] = prev[j-1];
                }

                else if(s1[i-1]=='*')
                {
                    curr[j] = prev[j] or curr[j-1];
                }

                else
                {
                    curr[j] = false;
                }
            }
            prev=curr;
        }
        return prev[m];        
    }
};

// cannot be optimised further to 1d dp 
