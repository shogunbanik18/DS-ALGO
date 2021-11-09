#include <bits/stdc++.h>
// #include "queue.h"
using namespace std;

// int main()
// {
//     Queue my(7);
//     my.push(1);
//     my.push(2);
//     my.push(3);
//     my.push(4);
//     my.push(5);
//     my.push(6);
//     my.push(7);
//     my.push(8);
//     my.pop();
//     my.pop();
//     my.push(9);

//     while (!my.empty())
//     {
//         cout << my.getfront() << endl;
//         my.pop();
//     }

//     return 0;
// }

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.pop();

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}
