class Solution {
public:
    // intutition 
    // find the longest palindromic subsequence length and then n-length
    
    // using tabulation dp 
    // tc: o(n*m)
    // sc:o(n+m)
    int palindromic_lcs(string s1,string s2)
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
    
    int minInsertions(string s) 
    {
        int n=s.size();
        string a=s;
        reverse(s.begin(),s.end());
        int ans=palindromic_lcs(a,s);
        ans =n-ans;
        return ans;
    }
};
