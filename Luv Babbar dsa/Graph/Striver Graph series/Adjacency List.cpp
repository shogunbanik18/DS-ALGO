#include<bits/stdc++.h>
using namespace std;

// Adjacency matrix 
// sc: o(n*n)
// int main()
// {
//     // n=nodes 
//     // m=edges 
//     int n,m;
//     cin>>n>>m;
    
//     int adj[n+1][n+1];
    
//     for(int i=0;i<m;i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         adj[u][v]=1;
//         adj[v][u]=1;
//     }
//     return 0;
// }


// Adjacency List representation 
// sc : (N+2E)
int main()
{
    // n=nodes 
    // m=edges 
    int n,m;
    cin>>n>>m;
    
    // incase of weighted graph 
    // use vector<pair<int,int>>adj[n+1]
    // adj[u].push_back({v,w}) u,v,w
    
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        
        // for undirected graph 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    return 0;
}
