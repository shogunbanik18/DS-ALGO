#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

void shogun()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

// // tc : o(n^2)
// // sc : o(1)
// void solve_shogun()
// {
// 	string s;
// 	cin >> s;

// 	int n = s.size();

// 	vector<string> v;

// 	for (int i = 0; i < n; i++)
// 	{
// 		string p = "";
// 		for (int j = i; j < n; j++)
// 		{
// 			p += s[j];
// 			v.push_back(p);
// 		}
// 	}

// 	for (auto x : v)
// 	{
// 		cout << x << " ";
// 	}
// 	cout << endl;

// 	return;
// }

// tc : o(n^3)
// sc : o(1)
void solve_shogun()
{
	string s;
	cin >> s;

	int n = s.size();

	vector<string> v;

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			for (int k = i; k <= j; k++)
			{
				cout << s[k];
			}
			cout << " ";

		}
	}
	return;
}


int main()
{
	shogun();
	int t;
	cin >> t;
	while (t--)
	{
		solve_shogun();
	}
}
