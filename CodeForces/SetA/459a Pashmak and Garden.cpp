#include<bits/stdc++.h>
using namespace std;

#define PI 3.14
typedef long long ll;

const int N = 0;


int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	if (x1 != x2 and y1 != y2 and abs(x1 - x2) != abs(y1 - y2))
	{
		cout << "-1" << endl;
	}
	else if (x1 == x2 )
	{
		cout << x1 + abs(y1 - y2) << " " << y1 << " " << x2 + abs(y1 - y2) << " " << y2 << endl;
	}
	else if (y1 == y2 )

	{
		cout << x1 << " " << y1 + abs(x1 - x2) << " " << x2 << " " << y2+abs(x1 - x2) << endl;
	}
	else
	{
		cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
	}

	return 0;
}
