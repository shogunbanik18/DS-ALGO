// // intuition : find the lcs of the string with its palindrome and the find length as n- lengths of lcs
// // using Recursion 
// // tc : o(2^n)
// // sc :o(1)
class Solution
{
public:
    
    int lcs(int ind1,int ind2 ,string s, string p)
    {
        if(ind1==0 or ind2==0)
        {
            return 0;
        }
        
        if(s[ind1]==p[ind2])
        {
            return  1 + lcs(ind1-1,ind2-1,s,p);
        }
        
        else
        {
            return 0 + max( lcs(ind1-1,ind2,s,p) , lcs(ind1,ind2-1,s,p) );
        }
    }
    
    int minInsertions(string s) 
    {
        int n =s.size();
        
        string p="";
        for(int i= n -1 ; i>=0 ; i--)
        {
            p += s[i];
        }
        
        cout<<p<<endl;
        int m = p.size();
        
        int x = lcs(n-1,m-1,s,p);
        cout<<x<<endl;
        
        
        int ans = n-x;
        
        return ans;
    }
};

// // // using Recursion + memoisation
// // // tc : o(n*m)
// // // sc :o(n*m) + o(n+m)
class Solution
{
public:
    
    int lcs(int ind1,int ind2 ,string s, string p , vector<vector<int>>& dp)
    {
        if(ind1==0 or ind2==0)
        {
            return 0;
        }
        
        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }
        
        if(s[ind1-1]==p[ind2-1])
        {
            return dp[ind1][ind2] = 1 + lcs(ind1-1,ind2-1,s,p,dp);
        }
        
        else
        {
            return dp[ind1][ind2] = 0 + max( lcs(ind1-1,ind2,s,p,dp) , lcs(ind1,ind2-1,s,p,dp) );
        }
    }
    
    int minInsertions(string s) 
    {
        int n =s.size();
        
        string p="";
        for(int i= n -1 ; i>=0 ; i--)
        {
            p += s[i];
        }
        
        cout<<p<<endl;
        int m = p.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int x = lcs(n,m,s,p,dp);
        cout<<x<<endl;
        
        
        int ans = n-x;
        
        return ans;
    }
};


// // using Tabulation
// // tc : o(n*m)
// // sc : o(n+m)
class Solution
{
public:
    int palindromic_lcs(string s,string p)
    {
        int n = s.size();
        int m = p.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        // base case
        
        // ind1=0
        for(int ind2=0;ind2<=m;ind2++)
        {
            dp[0][ind2] = 0;
        }
        
        // ind2=0
        for(int ind1=0;ind1<=n;ind1++)
        {
            dp[ind1][0] = 0;
        }
        
        
        // bottom up appraoch
        for(int ind1 =1;ind1<=n;ind1++)
        {
            for(int ind2 =1 ;ind2 <=m ;ind2++)
            {
                if(s[ind1-1]==p[ind2-1])
                {
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                }

                else
                {
                     dp[ind1][ind2] = 0 + max( dp[ind1-1][ind2] , dp[ind1][ind2-1]);
                }
            }
        }
        return dp[n][m];
        
    }
    
    
    int minInsertions(string s) 
    {
        int n =s.size();
        
        string p="";
        for(int i= n -1 ; i>=0 ; i--)
        {
            p += s[i];
        }
        
        cout<<p<<endl;
        int m = p.size();
        
        int x = palindromic_lcs(s,p);  

        cout<<x<<endl;
        
        int ans = n-x;
        
        return ans;
    }
};
