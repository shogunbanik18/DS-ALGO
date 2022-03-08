class Solution {
public:
    // using finding the lcs and the rinting with slight modification 
    
    // memoisation solution (TLE)
    // tc: o(n*m)
    // sc:o(n*m)+o(n+m)
//     string find_lcs(int ind1,int ind2,string s1,string s2,vector<vector<int>>&dp)
//     {
//         if(ind1==0 or ind2==0)
//         {
//             return 0;
//         }
        
//         if(s1[ind1-1]==s2[ind2-1])
//         {
//             return 1+ f(ind1-1,ind2-1,s1,s2,dp);
//         }
//         else
//         {
//             return 0+ max(f(ind-1,ind2,s1,s2,dp),f(ind1,ind2-1,s1,s2,dp));
//         }
        
//     }
    
//     string lcs(string s1,string s2)
//     {
//         int n=s1.size();
//         int m=s2.size();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//         find_lcs(n,m,s1,s2);
//     }
    
    // using tabulation dp 
    // tc: o(n*m)
    // sc:o(n*m)
    string lcs(string s1,string s2)
    {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        // base case 
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
                if(s1[ind1-1]==s2[ind2-1])
                {
                    dp[ind1][ind2]= 1+ dp[ind1-1][ind2-1];
                }
                else
                {
                    dp[ind1][ind2]= 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
            }
        }
        
        int len= dp[n][m];
        
//         for(int i=0;i<=n;i++)
//         {
//             for(int j=0;j<=m;j++)
//             {
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        // printing the strings 
        string res="";
        int i=n,j=m;
        while(i>0 and j>0)
        {
            if(s1[i-1]==s2[j-1])
            {
                res+=s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                res+=s1[i-1];
                i--;
            }
            else
            {
                res+=s2[j-1];
                j--;
            }
        }
        while(i>0)
        {
            res+=s1[i-1];
            i--;
        }
        while(j>0)
        {
            res+=s2[j-1];
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
    string shortestCommonSupersequence(string str1, string str2)
    {
        string ans=lcs(str1,str2);
        return ans;
    }
};
