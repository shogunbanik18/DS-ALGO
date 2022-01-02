#include<bits/stdc++.h>
using namespace std;

// using dfs traversal
bool iscycle(int src,vector<vector<int>>&adj,vector<bool>&visited,int parent)
{
    visited[src]=true;
    for(auto x:adj[src])
    {
        if(x!=parent)
        {
            if(visited[x])
            {
                return true;
            }
            if(!visited[x] and iscycle(x,adj,visited,src))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    // n= no. of nodes 
    // m= np. of edges 
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bool cycle=false;
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(!visited[i] and iscycle(i,adj,visited,-1))
        {
            cycle=true;
        }
    }
    
    if(cycle)
    {
        cout<<"Cycle is Present!"<<endl;
    }
    else
    {
        cout<<"Cycle is not present!"<<endl;
    }
    return 0;
}
