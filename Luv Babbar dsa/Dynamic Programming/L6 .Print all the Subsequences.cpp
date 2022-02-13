#include<bits/stdc++.h>
using namespace std;

// tc:o(2^n)
const int N = 0;

void print(int ind, vector<int>&ds, int arr[], int n)
{
	if (ind == n)
	{
		if (ds.size() == 0)
		{
			cout << "{}" << " ";
		}
		for (auto x : ds)
		{
			cout << x << " ";
		}
		cout << endl;
		return;
	}

	// take case
	ds.push_back(arr[ind]);
	print(ind + 1, ds, arr, n);
	ds.pop_back();
	print(ind + 1, ds, arr, n);
}

int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int arr[] = {3, 1, 2};
	int n = 3;
	vector<int>ds;
	print(0, ds, arr, n);

	return 0;
}
