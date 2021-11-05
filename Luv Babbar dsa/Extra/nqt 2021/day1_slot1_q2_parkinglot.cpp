#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10][10];
    int row, col;
    int sum = 0;
    int i, j, in = 0;
    int m = INT_MIN;
    cin >> row >> col;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cin >> arr[i][j];
            sum = sum + arr[i][j];
        }
        if (sum > m)
        {
            m = sum;
            in = i + 1;
        }
        sum = 0;
    }
    cout << in << endl;
}
