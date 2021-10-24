#include <bits/stdc++.h>
using namespace std;

vector<int> WavePrint(int m, int n, vector<vector<int>> arr)
{
    vector<int> result;

    /* m 	- Ending row index
        n 	- Ending column index
        i, j 	- Iterator
        wave 	- for Direction
        wave = 1 - Wave direction down
        wave = 0 - Wave direction up   */

    int i, j = n - 1, wave = 1;
    while (j >= 0)
    {
        if (wave == 1)
        {
            for (i = 0; i < m; i++)
            {
                result.push_back(arr[i][j]);
            }
            wave = 0;
            j--;
        }
        else
        {
            for (i = m - 1; i >= 0; i--)
            {
                result.push_back(arr[i][j]);
            }
            wave = 1;
            j--;
        }
    }
    return result;
    // your code goes here
}

// int main()
// {
//     int arr[][10] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
//     int n = 4, m = 4;
//     waveprint(n, m, arr);
//     return 0;
// }
