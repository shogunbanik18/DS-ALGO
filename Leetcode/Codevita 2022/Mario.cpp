#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<ll, ll>
#define pi pair<int, int>
#define mp make_pair
#define setbits(x) __builtin_popcountll(x)
#define sp(x, y) fixed << setprecision(y) << x
#define endl "\n"
#define debug(x) cout << #x << " -> " << x << "\n";
const ll mod = 1000000007;
const ll MOD = 998244353;
const ll inf = 1e18;


void shogun()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

ll mario_points = 0, ans = 0;

// shogun_solve function
void shogun_solve()
{
    // inputs
    ll a, b, i, j;
    cin >> a >> b;

    // string
    string res;

    vector<string>arr(a);

    vector<vector<ll>> grid (a, vector<ll>(b, 0));

    for (i = 0; i < a; i++)
    {
        cin >> arr[i];
    }

    // Debug
    // for(i=0;i<a;i++){
    //    for(j=0;j<b;j++){
    //        cout<<arr[i][j];
    //    }cout<<"\n";
    // }


    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            if (i == 0)
            {
                if (arr[i][j] == 'C')
                {
                    mario_points++;
                    grid[i][j] = a - i - 1;
                }
            }

            else
            {
                if (arr[i][j] == 'C')
                {
                    mario_points++;
                    ll p  = a - i - 1;
                    grid[i][j] = min(grid[i - 1][j], -p);
                }

                else if (arr[i][j] == 'H')
                {
                    if (arr[i - 1][j] == 'H')
                    {
                        grid[i][j] = grid[i - 1][j];
                    }

                    else
                    {
                        grid[i][j] = a - i;
                    }
                }

                else if (grid[i - 1][j] < 0)
                {
                    grid[i][j] = grid[i - 1][j];
                }
            }
        }
    }


    for (i = 0; i < b; i++)
    {
        if (grid[a - 1][i] < 0)
        {
            ll q = grid[a - 1][i];
            ans += -q;
        }
        else
        {
            ans += grid[a - 1][i];
        }
    }

    ans = 2 * ans;
    cout << mario_points << " " << ans;

    return;
}

int main()
{
    // shogun();
    shogun_solve();
}


// i/p test case 
5 10
0000000000
0CCC00000H
OCCCOH0000
00000H0H0H
00000H0H0H

// o/p ans  
0000000000
0CCC00000H
OCCCOH0000
00000H0H0H
00000H0H0H

0000000000
0-3-3-3000004
0-3-3-3030000
0-3-3-3030202
0-3-3-3030202
6 32
