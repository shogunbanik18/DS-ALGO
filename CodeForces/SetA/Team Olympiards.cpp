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

// tc:o(n)
// sc:o(1)
int main()
{
	c_p_c();

	int n;
	cin >> n;
	int arr[n];
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	int arr1[n], arr2[n], arr3[n];
	int count1 = 0, count2 = 0, count3 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] == 1)
		{
			arr1[count1] = i;
			count1++;
		}
		else if (arr[i] == 2)
		{
			arr2[count2] = i;
			count2++;
		}
		else if (arr[i] == 3)
		{
			arr3[count3] = i;
			count3++;
		}
	}

	if (count1 == 0 or count2 == 0 or count3 == 0)
	{
		cout << 0 << endl;
	}
	else
	{
		int mini = min(count1, min(count2, count3));
		cout << mini << endl;

		for (int i = 0; i < mini; i++)
		{
			cout << arr1[i] << " " << arr2[i] << " " << arr3[i] << endl;
		}
	}

	return 0;
}
