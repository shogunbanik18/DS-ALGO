#include <bits/stdc++.h>
using namespace std;

void printarray(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void fillarray(vector<int> &arr, int i, int n, int val)
{
    // base case
    if (i == n)
    {
        printarray(arr, n);
        return;
    }
    arr[i] = val;
    fillarray(arr, i + 1, n, val + 1);
    // Backtracking step
    arr[i] = -1 * arr[i];
}

int main()
{
    // int arr[100] = {0};
    vector<int> arr(100, 0);
    int n;
    cin >> n;
    fillarray(arr, 0, n, 1);
    cout << endl;
    printarray(arr, n);
}

// vectors (STL data structures are passed by value)
// to pass it by reference we use & sign
// vector<int> &arr
