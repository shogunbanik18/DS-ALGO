#include <bits./stdc++.h>
using namespace std;

int main()
{
    vector<int> a{4, 5, 6, 7, 0, 1, 2, 3};
    reverse(a.begin(), a.end());
    for (int x : a)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}