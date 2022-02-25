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
		int n, k;
		cin >> n >> k;

		if (n > 1 and k == 1)
		{
			cout << -1 << endl;
			continue;
		}

		vector<int>v;
		for (int i = 1; i <= n; i++)
		{
			v.push_back(i);
		}

		reverse(v.end() - (n - k + 1), v.end());

		for (auto x : v)
		{
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}
