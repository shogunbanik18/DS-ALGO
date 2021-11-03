#include <bits/stdc++.h>
using namespace std;

int main()
{
    int weight;
    cin >> weight;

    if (weight == 0)
    {
        cout << "Time estimated is 0 min" << endl;
    }
    else if (weight > 0 and weight <= 2000)
    {
        cout << "Time estimated is 25 min" << endl;
    }
    else if (weight > 2000 and weight <= 4000)
    {
        cout << "Time estimated is 35 min" << endl;
    }
    else if (weight > 4000 and weight <= 7000)
    {
        cout << "Time estimated is 45 min" << endl;
    }
    else if (weight > 7000)
    {
        cout << "OVERLOADED" << endl;
    }
    else
    {
        cout << "Invalidoutput" << endl;
    }
    return 0;
}