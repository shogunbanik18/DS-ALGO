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

// Subsequences of a given string using recursion
// Using Recursion and Backtracking 
void find(int ind, vector<char>&ds, char arr[], int n)
{
	vector<int>ans;
	if (ind == n)
	{
		for (auto x : ds)
		{
			cout << x << " ";
		}
		if (ds.size() == 0)
		{
			cout << "{}" << endl;
		}
		cout << endl;
		return ;
	}
	ds.push_back(arr[ind]);
	find(ind + 1, ds, arr, n);
	ds.pop_back();
	find(ind + 1, ds, arr, n);
}

int main()
{
	c_p_c();
	int n = 3;
	char arr[3] = {'a', 'b', 'c'};
	vector<char>ds;
	find(0, ds, arr, n);
	return 0;
}
