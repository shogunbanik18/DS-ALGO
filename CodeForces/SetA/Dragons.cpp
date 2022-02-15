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

	ll s, n;
	cin >> s >> n;
	pair<int, int > arr[1000];
	bool ans = true;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		if (s <= arr[i].first)
		{
			ans = false;
			break;
		}
		else if (s > arr[i].first)
		{
			s = s + arr[i].second;
		}
	}
	if (ans == true)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}
