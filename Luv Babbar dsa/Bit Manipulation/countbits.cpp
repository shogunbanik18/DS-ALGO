// count bits 
#include <bits/stdc++.h>
using namespace std;

int count_bits(int n)
{
    int count = 0;
    while (n > 0)
    {
        int lastbit = (n & 1);
        count = count + lastbit;
        n = n >> 1;
    }
    return count;
}

int count_bits_hack(int n)
{
    int ans = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        ans++;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << count_bits(n) << endl;
    cout << count_bits_hack(n) << endl;
    return 0;
}
