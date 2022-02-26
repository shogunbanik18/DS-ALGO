// // TCS Digital Hiring Challenge

// 1. using sorting and iterating
// tc:o(n)
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

int main()
{
	c_p_c();

	int n;
	cin >> n;
	vector<int>arr(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	// for (auto x : arr)
	// {
	// 	cout << x << " ";
	// }
	// cout << endl;


	for (int i = 0; i < n - 1; i++)
	{
		if (i % 2 == 0)
		{
			if (arr[i] >= arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
			}
			else
			{
				continue;
			}
		}
		else if (i % 2 != 0)
		{
			if (arr[i] <= arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
			}
			else
			{
				continue;
			}
		}
	}

	for (auto x : arr)
	{
		cout << x << " ";
	}
	cout << endl;

	return 0;
}

// Book Allocation Problem
// using Binary Search
// tc:o(logn)
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

int solve(int n, int f, vector<int>&arr)
{
	int mini = INT_MAX;
	for (auto x : arr)
	{
		mini = min(mini, x);
	}

	int maxi = 0;
	int l = 1;
	int r = mini;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		int count = 0;

		for (auto x : arr)
		{
			count += x / mid;
		}

		if (count < f)
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
			maxi = max(maxi, mid);
		}
	}
	return maxi;
}


int main()
{
	c_p_c();

	int n, f;
	cin >> n >> f;

	vector<int>arr(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << solve(n, f, arr);
	return 0;
}
