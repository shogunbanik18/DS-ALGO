#include <bits/stdc++.h>
#include <math.h>
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

void showpq(priority_queue<int>pq)
{
    priority_queue<int>g = pq;
    while (!g.empty())
    {
        cout << g.top() << " ";
        g.pop();
    }
    cout << endl;
}

// Priority queue
void solve()
{
    priority_queue<int>pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(1);

    cout << "The Priority Queue is : " << " ";
    showpq(pq);

    cout << "\npq.size() : " << pq.size();
    cout << "\npq.top() : " << pq.top();

    cout << "\npq.pop() : ";
    pq.pop();
    showpq(pq);

    return;
}

int main()
{
    c_p_c();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
