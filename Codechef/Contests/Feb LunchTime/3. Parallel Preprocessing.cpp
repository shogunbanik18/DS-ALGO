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

	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;

		vector<ll>v(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		ll sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += v[i];
		}
    
		ll mini = sum;
		ll s = 0;
    
		for (int i = 0; i < n; i++)
		{
			s += v[i];
			ll maxi = max(s, sum - s);
			mini = min(maxi, mini);
		}
		cout << mini << endl;
	}

	return 0;
}
