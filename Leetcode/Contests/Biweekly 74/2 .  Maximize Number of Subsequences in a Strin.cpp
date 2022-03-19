class Solution {
public:
    
//     int  find(string s, string p)
//     {
//         long long x1,x2;
//         map<char,long long >mp;
//         for(auto x: s)
//         {
//             mp[x]++;
//         }
        
//         for(auto x: mp)
//         {
//             cout<<x.first<<" "<<x.second<<endl;
//         }
        
//        for(auto x: mp)
//        {
//            if(mp.find(p[0])!=mp.end())
//            {
//                x1 = x.second;
//            }
           
//            if(mp.find(p[1])!=mp.end())
//            {
//                 x2 = x.second;
//            }
//        }
        
//         cout<<x1<<" "<<x2<<endl;
//         return x1*x2;
//     }
    
//     long long maximumSubsequenceCount(string text, string pattern) 
//     { 
//         char s1 = pattern[1];
        
//         text += s1;
//         cout<<text<<endl;
//         return find(text,pattern);
//     }
// };

// using dp based approach 
    long long findSubsequenceCount(string S, string P)
    {
        long long m = P.length(), n = S.length();

 
        if (m > n)
            return 0;

        // using dp vector
        vector<vector<long long >> dp(m+1,vector<long long>(n+1));
        
        for (long long i = 1; i <= m; i++)
            dp[i][0] = 0;

        
        for (long long j = 0; j <= n; j++)
            dp[0][j] = 1;

        
        for (long long i = 1; i <= m; i++) {
            for (long long j = 1; j <= n; j++) {

                
                if (P[i - 1] != S[j - 1])
                    dp[i][j] = dp[i][j - 1];

               
                else
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
            }
        }

        return dp[m][n];
    }
        
  
    long long maximumSubsequenceCount(string text, string pat) 
    {
        string s1 = pat[0]+text;
        string s2 = text+pat[1];
        long long n= s1.size();
        long long m= pat.size();
        
        long long n1=findSubsequenceCount(s1,pat);
        long long  n2=findSubsequenceCount(s2,pat);
        return max(n1,n2);
    }
};
