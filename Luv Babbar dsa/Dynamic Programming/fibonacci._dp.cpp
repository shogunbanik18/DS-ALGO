#include <bits/stdc++.h>
using namespace std;

// Top Down Approach
int fib(int n, int dp[])
{
    if (n == 0 or n == 1)
    {
        return n;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

// Bottom up (Iterative Approach)
int fib2(int n)
{
    int dp[n + 1] = {0};
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    return dp[n];
}

int main()
{
    int n = 5;
    int dp[100];
    // cout << fib(n, dp) << endl;
    cout << fib2(n) << endl;
    return 0;
}
