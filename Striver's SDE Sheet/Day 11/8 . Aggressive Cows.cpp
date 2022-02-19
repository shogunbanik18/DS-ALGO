// using Binary Search
// tc: o(n)*log(n)
// sc:o(1)
#include<bits/stdc++.h>
using namespace std;

bool canplace(vector<int>&arr, int n, int cows, int dist)
{
	int coord = arr[0];
	int count = 1;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] - coord >= dist)
		{
			count++;
			coord = arr[i];
		}
	}
	if (count == cows)
	{
		return true;
	}
	return false;
}

int main()
{
	// int n = 5, cows = 3;
	int n, cows;
	cin >> n >> cows;
	// vector<int> arr = {1, 2, 4, 8, 9};
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	// int n=arr.size();

	int low = arr[0];
	int high = arr[n - 1] - arr[0];
	int res = 0;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (canplace(arr, n, cows, mid))
		{
			res = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	cout << res << endl;
	// return res;
}
