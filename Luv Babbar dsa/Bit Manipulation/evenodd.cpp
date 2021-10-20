// using bitmanipulation to check even/odd numbers 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    if (x & 1)
    {
        cout << "Odd" << endl;
    }
    else
    {
        cout << "Even" << endl;
    }
}