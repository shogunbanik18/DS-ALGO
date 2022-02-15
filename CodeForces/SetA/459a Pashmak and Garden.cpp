#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define PI 3.14
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef long long ll;


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
	c_p_c();

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	if (x1 != x2 and y1 != y2 and abs(x1 - x2) != abs(y1 - y2))
	{
		cout << "-1" << endl;
	}
	else if (x1 == x2 and y1 != y2)
	{
		cout << x1 + abs(y1 - y2) << " " << y1 << " " << x2 + abs(y1 - y2) << " " << y2 << endl;
	}
	else if (y1 == y2 and x1 != x2)

	{
		cout << x1 << " " << y1 + abs(x1 - x2) << " " << x2 << " " << abs(x1 - x2) << endl;
	}
	else
	{
		cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
	}
	return 0;
}
