#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int count1 = 0, count2 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '*')
        {
            count1++;
        }
        else if (s[i] == '#')
        {
            count2++;
        }
    }

    if (count1 > count2)
    {
        cout << count1 - count2 << endl;
    }
    else
    {
        cout << count2 - count1 << endl;
    }
}
