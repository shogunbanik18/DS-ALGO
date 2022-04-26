// // using prism algo
// // brute force

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<pair<int, int>> adj[n];

//     for (int i = 0; i < n; i++)
//     {
//         int a, b, wt;
//         cin >> a >> b >> wt;
//         adj[a].push_back({b, wt});
//         adj[b].push_back({a, wt});
//     }

//     vector<int> parent(n);
//     vector<int> key(n);
//     vector<bool> mst(n);

//     for (int i = 0; i < n; i++)
//     {
//         key[i] = INT_MAX;
//         parent[i] = -1;
//         mst[i] = false;
//     }

//     key[0] = 0;

//     // n-1 edges
//     for (int count = 0; count < n - 1; count++)
//     {
//         int mini = 1e9, u;

//         for (int v = 0; v < n; v++)
//         {
//             if (mst[v] == false and key[v] < mini)
//             {
//                 mini = key[v];
//                 u = v;
//             }
//         }

//         mst[u] = true;

//         for (auto x : adj[u])
//         {
//             int a = x.first;
//             int weight = x.second;

//             if (mst[a] == false and weight < key[a])
//             {
//                 parent[a] = u;
//                 key[a] = weight;
//             }
//         }

//         for (int i = 0; i < n; i++)
//         {
//             cout << parent[i] << "-" << i << endl;
//         }
//     }
// }

// using prism algo
// tc : o(nlogn) + o(n + e)
// using priority queue
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];

    for (int i = 0; i < n; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }

    vector<int> parent(n);
    vector<int> key(n);
    vector<bool> mst(n);

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    key[0] = 0;
    // key val and index
    pq.push({0, 0});

    // n-1 edges
    for (int count = 0; count < n - 1; count++)
    {
        int mini = 1e9, u;

        auto u = pq.top().second;
        pq.pop();

        mst[u] = true;

        for (auto x : adj[u])
        {
            int a = x.first;
            int weight = x.second;

            if (mst[a] == false and weight < key[a])
            {
                parent[a] = u;
                pq.push({key[a], u});
                key[a] = weight;
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << parent[i] << "-" << i << endl;
        }
    }
}
