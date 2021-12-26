#include<bits/stdc++.h>
using namespace std;

// tc: O(N)+2E
// sc:O(N)+2E

int main()
{
    // n=nodes
    // m=edges 
    int n,m;
    cin>>n>>m;
    
    // undirected graph
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    
    // directed graph 
    // vector<int>adj[n+1];
    // for(int i=0;i<m;i++)
    // {
    //     int u,v;
    //     cin>>u>>v;
        
    //     adj[u].push_back(v);
    // }
    
    
    // weighted graph 
    // vector<pair<int,int>>adj[n+1];
    // for(int i=0;i<m;i++)
    // {
    //     int u,v,w;
    //     cin>>u>>v>>W;
        
    //     adj[u].push_back({v,w});
    //     adj[v].push_back({u,w});
    // }
    return 0;
}
