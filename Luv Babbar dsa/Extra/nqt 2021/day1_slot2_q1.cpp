#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int arr[] = {7, 4, 8, 2, 9};
    int arr[] = {3, 4, 5, 8, 9};
    int n = sizeof(arr) / sizeof(int);

    int count = 1;
    for (int i = 1; i <= n - 1; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            count++;
        }
    }
    cout << count << endl;
}
