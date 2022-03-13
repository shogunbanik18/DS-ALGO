// // using Recursion 
// // tc : Exponential 
// // sc : (n+m)
// class Solution {
// public:
    
//     // f(i,j) = f(n-1,j-1) signifies that minimum no of operations required to convert
//         // s[0....i] to t[0....j]
    
//     int f(int i,int j,string s,string t)
//     {
//         // base case 
        
//         // f(0,j) = f(0,j-1) signifies that minimum no of operations required to convert
//         // empty string s to t[0....j] i.e by insertion 
//         if(i<0)
//         {
//             return j+1;
//         }
    
//         // f(i,0) = f(i-1,0) signifies that minimum no of operations required to convert
//         // empty string s[0...i] to empty string t i.e by deletion 
//         if(j<0)
//         {
//             return i+1;
//         }
        
//         if(s[i]==t[j])
//         {
//             return 0 + f(i-1,j-1,s,t); 
//         }
//         else
//         {
//             // 3 possible case 
//             int insert1 = 1 + f(i,j-1,s,t);
//             int delete1 = 1 + f(i-1,j,s,t);
//             int replace1 = 1 +f(i-1,j-1,s,t);
            
//             return min(insert1 , min(delete1,replace1));
//         }
//     }
    
//     int minDistance(string word1, string word2) 
//     {
//         int n=word1.size();
//         int m=word2.size();
//         return f(n-1,m-1,word1,word2);
//     }
// };


// // using Memoisation  
// // tc : o(n*m) 
// // sc : o(n*m)+(n+m)
// class Solution {
// public:
    
//     // f(i,j) = f(n-1,j-1) signifies that minimum no of operations required to convert
//         // s[0....i] to t[0....j]
//     int f(int i,int j,string s,string t,vector<vector<int>>&dp)
//     {
//         // base case 
//         if(i<0)
//         {
//             return j+1;
//         }

//         if(j<0)
//         {
//             return i+1;
//         }
        
//         if(dp[i][j]!=-1)
//         {
//             return dp[i][j];
//         }
        
//         if(s[i]==t[j])
//         {
//             return  dp[i][j]= 0 + f(i-1,j-1,s,t,dp); 
//         }
//         else
//         {
//             // 3 possible case 
//             int insert1 = 1 + f(i,j-1,s,t,dp);
//             int delete1 = 1 + f(i-1,j,s,t,dp);
//             int replace1 = 1 +f(i-1,j-1,s,t,dp);
            
//             return dp[i][j]= min(insert1 , min(delete1,replace1));
//         }
//     }
    
//     int minDistance(string word1, string word2) 
//     {
//         int n=word1.size();
//         int m=word2.size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return f(n-1,m-1,word1,word2,dp);
//     }
// };


// // using Memoisation  and shifting of index
// // tc : o(n*m) 
// // sc : o(n*m)+(n+m)
// class Solution {
// public:
    
//     // f(i,j) = f(n,m) signifies that minimum no of operations required to convert
//         // s[1....i] to t[1....j]
//     int f(int i,int j,string s,string t,vector<vector<int>>&dp)
//     {
//         // base case 
//         if(i==0)
//         {
//             return j;
//         }

//         if(j==0)
//         {
//             return i;
//         }
        
//         if(dp[i][j]!=-1)
//         {
//             return dp[i][j];
//         }
        
//         if(s[i-1]==t[j-1])
//         {
//             return  dp[i][j]= 0 + f(i-1,j-1,s,t,dp); 
//         }
//         else
//         {
//             // 3 possible case 
//             int insert1 = 1 + f(i,j-1,s,t,dp);
//             int delete1 = 1 + f(i-1,j,s,t,dp);
//             int replace1 = 1 +f(i-1,j-1,s,t,dp);
            
//             return dp[i][j]= min(insert1 , min(delete1,replace1));
//         }
//     }
    
//     int minDistance(string word1, string word2) 
//     {
//         int n=word1.size();
//         int m=word2.size();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//         return f(n,m,word1,word2,dp);
//     }
// };


// // using Tabulation Bottom up 
// // tc : o(n*m) 
// // sc : o(n*m)
// class Solution {
// public:
    
//     // dp[i][j] = dp[n][m] signifies that minimum no of operations required to convert
//         // s[1....i] to t[1....j]
//     int minDistance(string s, string t) 
//     {
//         int n=s.size();
//         int m=t.size();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
//         // base case 
//         for(int j=0;j<=m;j++)
//         {
//             dp[0][j]=j;
//         }
        
//         for(int i=0;i<=n;i++)
//         {
//             dp[i][0]=i;
//         }
        
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=m;j++)
//             {
//                 if(s[i-1]==t[j-1])
//                 {
//                     dp[i][j] = 0 + dp[i-1][j-1]; 
//                 }
//                 else
//                 {
//                     // 3 possible case 
//                     int insert1 = 1 + dp[i][j-1];
//                     int delete1 = 1 + dp[i-1][j];
//                     int replace1 = 1 + dp[i-1][j-1];

//                     dp[i][j]= min(insert1 , min(delete1,replace1));
//                 }
//             }
//         }
        
//         for(int i=0;i<=n;i++)
//         {
//             for(int j=0;j<=m;j++)
//             {
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         return dp[n][m];
//     }
// };


// using Space optimisation Bottom up 
// tc : o(n*m) 
// sc : o(n+m)
class Solution {
public:
    
    // dp[i][j] = dp[n][m] signifies that minimum no of operations required to convert
        // s[1....i] to t[1....j]
    int minDistance(string s, string t) 
    {
        int n=s.size();
        int m=t.size();
        vector<int>prev(m+1,0),curr(m+1,0);
        
        // base case 
        for(int j=0;j<=m;j++)
        {
            prev[j]=j;
        }
        
        for(int i=1;i<=n;i++)
        {
            // every row 1st column is i check dp table 
            curr[0]=i;
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    curr[j] = 0 + prev[j-1]; 
                }
                else
                {
                    // 3 possible case 
                    int insert1 = 1 + curr[j-1];
                    int delete1 = 1 + prev[j];
                    int replace1 = 1 + prev[j-1];

                    curr[j]= min(insert1 , min(delete1,replace1));
                }
            }
            prev=curr;
        }
        
        // for(int i=0;i<=n;i++)
        // {
        //     cout<<prev[i]<<" ";
        // }
        // cout<<endl;
        return prev[m];
    }
};

// cannot be space otimised further to 1 d because it is dependent on both the curr and the previous 
