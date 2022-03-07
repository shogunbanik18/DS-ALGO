#include <bits/stdc++.h>
using namespace std;

#define ll long long
void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

// Leetcode
class Solution {
public:

    // using lcs concept
    int palindromic_lcs(string s1, string s2)
    {
        // lcs dp
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
        for (int ind2 = 0; ind2 <= m; ind2++)
        {
            dp[0][ind2] = 0;
        }

        for (int ind1 = 0; ind1 <= n; ind1++)
        {
            dp[ind1][0] = 0;
        }

        for (int ind1 = 1; ind1 <= n; ind1++)
        {
            for (int ind2 = 1; ind2 <= m; ind2++)
            {
                if (s1[ind1 - 1] == s2[ind2 - 1])
                {
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                }
                else
                {
                    dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
                }
            }
        }

        Printing the palindrome lcs 
    	for (int i = 0; i <= n; i++)
    	{
    		for (int j = 0; j <= m; j++)
    		{
    			cout << dp[i][j] << " ";
    		}
    		cout << endl;
    	}

    	string pal = "";
    	int len = dp[n][m];
    	for (int i = 0; i < len; i++)
    	{
    		pal += '$';
    	}
    	cout << pal << endl;

    	int idx = len - 1;
    	int i = n, j = m;
    	while (i > 0 and j > 0)
    	{
    		if (s1[i - 1] == s2[j - 1])
    		{
    			pal[idx] = s1[i - 1];
    			idx--;
    			i = i - 1;
    			j = j - 1;
    		}
    		else if (dp[i - 1][j] > dp[i][j - 1])
    		{
    			i = i - 1;
    		}
    		else
    		{
    			j = j - 1;
    		}
    	}

    	cout << pal << endl;
        return dp[n][m];
    }
    
    int longestPalindromeSubseq(string s)
    {
        string a=s;
        reverse(s.begin(),s.end());
        int ans=palindromic_lcs(a,s);
        return ans;
    }
};
