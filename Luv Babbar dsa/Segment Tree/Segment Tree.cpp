#include <bits/stdc++.h>
using namespace std;

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int a[1000005], seg[1000005];

// building the segment tree
void build(int ind, int low, int high)
{
	if (low == high)
	{
		seg[ind] = a[low];
		return;
	}
	int mid = (low + high) / 2;
	build(2 * ind + 1, low, mid);
	build(2 * ind + 2, mid + 1, high);
	seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

// 3 case
// 1. completely lie
// 2. doesn't lie
// 3. overlaps
int query(int ind , int low, int high, int l, int r)
{
	if (low >= l and high <= r)
	{
		return seg[ind];
	}
	if (high<l or low>r)
	{
		return INT_MIN;
	}
	int mid = (low + high) / 2;
	int left = query(2 * ind + 1, low, mid, l, r);
	int right = query(2 * ind + 2, mid + 1, high, l, r);
	return max(left, right);
}

int main()
{
	c_p_c();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	build(0, 0, n - 1);

	// queries
	int q;
	cin >> q;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		cout << query(0, 0, n - 1, l, r) << endl;
	}
	return 0;
}


// eg.1
// 9
// 5 2 4 1 3 7 6 4 5
// 3
// 1 2
// 2 5
// 4 8
// o/p : 4,7,7


// eg.2 
// 10
// 8 2 5 1 4 5 3 9 6 10
// 1
// 3 8 
// o/p : 9




