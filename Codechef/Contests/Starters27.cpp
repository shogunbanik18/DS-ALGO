// #include <bits/stdc++.h>
// #include <math.h>
// using namespace std;

// #define PI 3.14
// #define _USE_MATH_DEFINES
// #define ll long long
// #define pb push_back
// #define ff first
// #define ss second
// #define pii pair<ll, ll>
// #define pi pair<int, int>
// #define mp make_pair
// #define setbits(x) __builtin_popcountll(x)
// #define sp(x, y) fixed << setprecision(y) << x
// #define endl "\n"
// #define debug(x) cout << #x << " -> " << x << "\n";
// const ll mod = 1000000007;
// const ll MOD = 998244353;
// const ll inf = 1e18;

// void c_p_c()
// {
// 	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// }

// int main()
// {
// 	c_p_c();

// 	int t;
// 	cin >> t;
// 	while (t--)
// 	{
// 		string s;
// 		cin >> s;

// 		ll int n = s.length();
// 		ll int i = 0, j = n - 1;

// 		// cout << s[i] << " " << s[j] << endl;
// 		ll int ans = 0;
// 		while (i < j)
// 		{
// 			if (s[i] != s[j])
// 			{
// 				// cout << s[i] << " " << s[j] << endl;
// 				ans = (j - i) + (n - 1 - j);
// 				break;
// 			}
// 			i++;
// 			j--;
// 		}
// 		cout << ans << endl;
// 	}

// 	return 0;
// }


#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define PI 3.14
#define _USE_MATH_DEFINES
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<ll, ll>
#define pi pair<int, int>
#define mp make_pair
#define setbits(x) __builtin_popcountll(x)
#define sp(x, y) fixed << setprecision(y) << x
#define endl "\n"
#define debug(x) cout << #x << " -> " << x << "\n";
const ll mod = 1000000007;
const ll MOD = 998244353;
const ll inf = 1e18;

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main()
{
	c_p_c();

	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;

		string temp = s;
		reverse(s.begin(), s.end());

		int len = s.size();
		int count = 0;
		for (int i = 0, j = i; i < len; i++, j++)
		{
			while (i < len and temp[i] != s[j])
			{
				i++;
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
