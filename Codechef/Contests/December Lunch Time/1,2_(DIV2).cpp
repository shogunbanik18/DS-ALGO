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


// tc:o(nlogn)
int main()
{
	c_p_c();

	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		vector<int>arr(n, 0);

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		ll maxi = (long long )(arr[n - 1] - arr[0]) * arr[n - 2];
		cout << maxi << endl;
	}

	return 0;
}


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
// 		int n, k;
// 		cin >> n >> k;

// 		string s1;
// 		cin >> s1;

// 		for (int i = 1; i < k; i++)
// 		{
// 			reverse(s1.begin(), s1.begin() + k + 1 - i);
// 			cout << s1 << endl;
// 		}

// 		cout << s1 << endl;
// 	}

// 	return 0;
// }


// using 2 pointer + substring appraoch
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
		string s;
		cin >> s;

		string ans;
		int i = 0;
		int j = k - 1;
		while (i < j)
		{
			ans += s[i];
			ans += s[j];
			j--;
			i++;
		}
		if (i == j)
		{
			ans += s[i];
		}

		reverse(ans.begin(), ans.end());
		ans += s.substr(k, n);
		cout << ans << endl;
	}

	return 0;
}
