// Brute Force :  TLE 
// tc : o(n^2 *n) ~ o(n^3)
// sc : o(1)
// Generating all possible susbstrings (use substr function) and then check for palindrome
class Solution {
public:
    
    bool ispalindrome(string s)
    {
        int i=0;
        int j=s.size()-1;
        
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    string longestPalindrome(string s) 
    {
        int n = s.size();
        
        if(n==0)
        {
            return "";
        }
        
        if(n==1)
        {
            return s;
        }
        
        // Find all the substrings of s 
        string res="";
        for(int i=0;i<n-1;i++)
        {
            for(int len=1; len<=n-i;len++)
            {
                if(ispalindrome(s.substr(i,len)))
                {
                    if(res.size()<len)
                    {
                        res = s.substr(i,len);
                    } 
                }
            }
        }
        return res;
    }
};


// using dp tabulation dp 
// tc : o(n*n)
// sc : o(n*n)
class Solution {
public:

    string longestPalindrome(string s) 
    {
        int n= s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        
        // for size 2 
        int start =0;
        int maxlength =1;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                start = i;
                maxlength = 2;
            }
        }
        
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i< n-k+1;i++)
            {
                // last element is j as 0 based indexing
                int j= i+k-1;
                
                if(dp[i+1][j-1]==1 and s[i]==s[j])
                {
                    dp[i][j]=1;
                    if(k>maxlength)
                    {
                        start = i ;
                        maxlength = k;
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
        cout<<start<<" "<<maxlength <<endl;
        return s.substr(start,maxlength);
    }
    
};
