#include <bits/stdc++.h>
using namespace std;

#define ll long long

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (i > n - j)
            {
                cout << "* ";
            }
            else
            {
                cout << "_ ";
            }
        }

        cout << endl;
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (i > n - j)
    //         {
    //             cout << "*" << " ";
    //         }
    //         else
    //         {
    //             cout << "_" << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    return;
}

int main()
{
    c_p_c();
    solve();
}
