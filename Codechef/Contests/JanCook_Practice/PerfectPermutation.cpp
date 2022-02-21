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
	freopen("output2.txt", "w", stdout);
#endif
}


int main()
{
	c_p_c();

	ll t;
	cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;

		vector<ll>v;
		for (ll i = 1; i <= n; i++)
		{
			v.push_back(i);
		}

		if (n == 1)
		{
			cout << 1 << endl;
		}
		else if (k == n - 1)
		{
			swap(v[0], v[1]);
			for (auto x : v)
			{
				cout << x << " ";
			}
			cout << endl;
		}
		else
		{
			int s = 0;
			int x = n - k;
			while (x--)
			{
				swap(v[s], v[s + 1]);
				s++;
			}

			for (auto j : v)
			{
				cout << j << " ";
			}
			cout << endl;
		}
	}

	return 0;
}
