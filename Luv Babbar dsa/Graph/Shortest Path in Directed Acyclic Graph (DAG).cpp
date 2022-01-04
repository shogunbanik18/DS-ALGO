// Shortestpath_in_direted_graph.cpp (DAG)
#include<bits/stdc++.h>
using namespace std;

// using the concept of topological sort 
void topo(int node,vector<int>vis,stack<int>&st,vector<pair<int,int>>adj[])
{
    vis[node]=1;
    for(auto x:adj[node])
    {
        if(!vis[x.first])
        {
            topo(x.first,vis,st,adj);
        }
    }
    st.push(node);
}


void shortestpath(int src,int n,vector<pair<int,int>>adj[])
{
    vector<int>vis(n,0);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            topo(i,vis,st,adj);
        }
    }
    
    int dist[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        
        if(dist[node]!=INT_MAX)
        {
            for(auto x:adj[node])
            {
                if(dist[node]+x.second<dist[x.first])
                {
                    dist[x.first]=dist[node]+x.second;
                }
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        (dist[i]==INT_MAX) ? cout<<"INF":cout<<dist[i]<<" ";
    }
}

int main()
{
    // n=no.of nodes
    // m=no.of edges 
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    shortestpath(0,n,adj);
    return 0;
}
