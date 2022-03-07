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

// Tabulation
// Bottom up dp
// tc: o(n*m)
// sc: o(n*m)
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
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
            if (text1[ind1 - 1] == text2[ind2 - 1])
            {
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            }
            else
            {
                dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    int len = dp[n][m];
    string ans = "";
    for (int i = 0; i < len; i++)
    {
        ans += '$';
    }

    cout << ans << endl;

    int ind = len - 1;
    int i = n, j = m;
    while (i > 0 and j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            ans[ind] = text1[i - 1];
            ind--;
            i--;
            j--;
        }

        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j = j - 1;
        }
    }
    cout << ans << endl;
    return dp[n][m];
}

int main()
{
    c_p_c();
    string s1;
    string s2 ;
    cin >> s1 >> s2;
    cout << longestCommonSubsequence(s1, s2);
    return 0;
}

