#include <bits/stdc++.h>
#include <math.h>
using namespace std;
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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			res = res ^ s[i];
		}
		if (res == 0)
		{
			cout << "-1" << endl;
		}
		else
		{
			cout << char(res) << endl;
		}
	}
	return 0;
}
