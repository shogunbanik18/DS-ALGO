#include<bits/stdc++.h>
using namespace std;


bool bipartitebfs(int src,vector<int>adj[],int color[])
{
    queue<int>q;
    q.push(src);
    color[src]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        
        for(auto x:adj[node])
        {
            if(color[x]==-1)
            {
                color[x]=1-color[node];
                q.push(x);
            }
            else if(color[x]==color[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool checkbipartite(vector<int>adj[],int n)
{
    int color[n];
    memset(color,-1,sizeof color);
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            if(!bipartitebfs(i,adj,color))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<int>adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    if(checkbipartite(adj,n))
    {
        cout<<"Yes"<<endl;
    }
    else 
    {
        cout<<"No"<<endl;
    }
}
