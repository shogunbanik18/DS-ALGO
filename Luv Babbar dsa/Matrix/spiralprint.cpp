#include <bits/stdc++.h>
using namespace std;

void spiralprint(int arr[][10], int n, int m)
{
    int startrow = 0;
    int endrow = n - 1;
    int startcol = 0;
    int endcol = m - 1;

    // outer loop conditions
    while (startrow <= endrow and startcol <= endcol)
    {
        // start row /
        for (int col = startcol; col <= endcol; col++)
        {
            cout << arr[startrow][col] << " ";
        }

        //  End Col /
        for (int row = startrow + 1; row <= endrow; row++)
        {
            cout << arr[row][endcol] << " ";
        }

        // End row /
        for (int col = endcol - 1; col >= startcol; col--)
        {
            if (startrow == endrow)
            {
                break;
            }
            cout << arr[endrow][col] << " ";
        }

        // start col /
        for (int row = endrow - 1; row >= startrow + 1; row--)
        {
            if (startcol == endcol)
            {
                break;
            }
            cout << arr[row][startcol] << " ";
        }

        // updating the loops
        startrow++;
        endrow--;
        startcol++;
        endcol--;
    }
}

int main()
{
    int arr[][10] = {{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};
    int n = 4, m = 4;
    spiralprint(arr, n, m);
    return 0;
}