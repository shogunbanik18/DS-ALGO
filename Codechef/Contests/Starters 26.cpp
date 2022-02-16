// Q 1
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
		int n;
		cin >> n;

		// n=weight
		int ans = 0;
		ans += 10 * n;
		cout << ans << endl;
	}

	return 0;
}

// Q2
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
		int n, x;
		cin >> n >> x;

		int count = x;
		int maxi = x;
		for (int i = 1; i <= n; i++)
		{
			int a;
			cin >> a;
			count = count + a;
			maxi = max(maxi, count);
		}
		cout << maxi << endl;
	}


	return 0;
}



// Q 3
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
		ll n, x, y;
		cin >> n;
		int arr[2 * n];
		bool ans = false;
		int sum = 0;
		for (int i = 0; i < 2 * n; i++)
		{
			cin >> arr[i];
			sum += arr[i];
		}
		if (sum % 2 == 0)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}


// Q 4
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
		int n, x, y;
		cin >> n >> x >> y;

		int a = 0 ;
		int b = 0;
		int c = 0;
		int n1 = n;
		int n2 = n;
		int n3 = n;

		while (n1 > 0)
		{
			n1 = n1 - 100;
			a += 1;
		}

		while (n2 > 0)
		{
			n2 = n2 - 4;
			b += 1;
		}

		while (n3 > 0)
		{
			if (n3 >= 100)
			{
				n3 = n3 - 100;
				c += x;
			}
			else
			{
				n3 = n3 - 4;
				c += y;
			}
		}
		int a1 = a * x;
		int b1 = b * y;
		int c1 = c;

		int ans = min(a1, b1);
		int res = min(ans, c1);
		cout << res << endl;
	}
	return 0;
}

// WRONG SUBMISSION
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
// 		int n, x, y;
// 		cin >> n >> x >> y;

// 		int ans = 0;
// 		if (x > y and n < 100)
// 		{
// 			ans += ((n / 4) + 1) * y;
// 		}
// 		else if (x <= y and n < 100)
// 		{
// 			ans += ((n / 100) + 1) * x;
// 		}
// 		else if (x > y and n >= 100)
// 		{
// 			ans += (n / 100) * x + (((n % 100) / 4) + 1) * y;
// 		}
// 		cout << ans << endl;
// 	}

// 	return 0;
// }
