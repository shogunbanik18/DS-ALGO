// Decimal to Bianry conversion
#include <bits/stdc++.h>
using namespace std;

// using naormal method
int dec2bin(int n)
{
    int ans = 0, pow = 1;
    int rem;
    while (n > 0)
    {
        rem = n % 2;
        ans = ans + rem * pow;
        pow = pow * 10;
        n = n / 2;
    }
    return ans;
}

// using bit manipulation
int decimal2binary(int n)
{
    int ans = 0;
    int pow = 1;
    while (n > 0)
    {
        int last_bit = (n & 1);
        ans = ans + pow * last_bit;
        pow = pow * 10;
        n = n >> 1;
    }
    return ans;
}


int main()
{
    int n;
    cin >> n;
    // cout << decimal2binary(n) << endl;
    cout << dec2bin(n) << endl;
    return 0;
}
