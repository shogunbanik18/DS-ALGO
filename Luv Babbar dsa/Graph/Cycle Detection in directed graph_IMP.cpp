#include<bits/stdc++.h>
using namespace std;

// using dfs traversal
// using the concept of stack 
bool iscycle(int src,vector<vector<int>>&adj,vector<bool>&visited,vector<int>&stack)
{
    stack[src]=true;
    if(!visited[src])
    {
        visited[src]=true;
        for(auto x:adj[src])
        {
            if(!visited[x] and iscycle(x,adj,visited,stack))
            {
                return true;
            }
            if(stack[x])
            {
                return true;
            }
        }
    }
    stack[src]=false;
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
    }
    
    bool cycle=false;
    vector<bool>visited(n,false);
    vector<int>stack(n,0);
    for(int i=0;i<n;i++)
    {
        if(!visited[i] and iscycle(i,adj,visited,stack))
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
