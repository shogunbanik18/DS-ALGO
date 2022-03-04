#include <bits/stdc++.h>
using namespace std;

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void lcs(string text1, string text2)
{
	int n = text1.size();
	int m = text2.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int j = 0; j <= m; j++)
	{
		dp[0][j] = 0;
	}

	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (text1[i - 1] == text2[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	// for(int i=0;i<n;i++)
	// {
	//     for(int j=0;j<m;j++)
	//     {
	//         cout<<dp[i][j]<<" ";
	//     }
	//     cout<<endl;
	// }

	int l = dp[n][m];
	string ans = "";
	int i = n;
	int j = m;
	for (int i = 0; i < l; i++)
	{
		ans += '#';
	}
	int len = l - 1;

	while (i > 0 and j > 0)
	{
		if (text1[i - 1] == text2[j - 1])
		{
			ans[len] = text1[i - 1];
			len--;
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i - 1][j - 1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}

	cout << ans << endl;
}

int main()
{
	// c_p_c();

	string s1 = "abcde";
	string s2 = "bdgek";
	lcs(s1, s2);
	return 0;
}
