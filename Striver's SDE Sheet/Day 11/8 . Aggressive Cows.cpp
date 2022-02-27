// Aggressive Cows
// Binary Search 
// tc: o(n*log(n)) + o(nlogn) for sorting 
// sc:o(1)
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

bool canplace(vector<int>&arr, int n, int cows, int mid)
{
	int coord = arr[0];
	int count = 1;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] - coord >= mid)
		{
			count++;
			coord = arr[i];
		}

		if (count == cows)
		{
			return true;
		}
	}
	return false;
}

void solve(vector<int>&arr, int n, int cows)
{
	int low = 1;
	// for eg 1 2 4 8 9
	// high=9-1=8 (search space)
	int high = arr[n - 1] - arr[0];
	int ans;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (canplace(arr, n, cows, mid))
		{
			ans = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	cout << ans << endl;
}

int main()
{
	c_p_c();

	ll t;
	cin >> t;
	while (t--)
	{
		int n, c;
		cin >> n >> c;
		vector<int>arr(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		solve(arr, n, c);
	}

	return 0;
}


// https://leetcode.com/discuss/general-discussion/1302335/aggressive-cows-spoj-fully-explained-c#:~:text=We%20need%20to%20define%20a,from%20the%20last%2Dplaced%20cow.
