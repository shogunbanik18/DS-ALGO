#include<bits/stdc++.h>
using namespace std;

bool bipartite(int node,vector<int>adj[],int color[])
{
    if(color[node]==-1)
    {
        color[node]=1;
        for(auto x : adj[node])
        {
            if(color[x]==-1)
            {
                color[x]=1-color[node];
                if(!bipartite(x,adj,color))
                {
                    return false;
                }
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
    // vector<int>color(n,-1);
    int color[n];
    memset(color,-1,sizeof color);
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            color[i]=1;
            if(!bipartite(i,adj,color))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    // n=no.of nodes 
    // m=no.of edges
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
    return 0;
}



// gfg code  
class Solution {
public:
    // using bfs 
    bool check(int i,int V, vector<int> adj[], vector<int> &color)
    {
        queue<int>q;
        q.push(i);
        color[i]=1;
        
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
    

  //     using dfs 
  //   tc: O(N+E)
  //   SC: O(N+E) +O(N)for color array  +O(N) for recursion 
    bool check(int node,vector<int>adj[],int color[])
    {
        // if(color[node]==-1)
        // {
            // color[node]=1;
            for(auto x:adj[node])
            {
                if(color[x]==-1)
                {
                    color[x]=1-color[node];
                    if(!check(x,adj,color))
                    {
                        return false;
                    }
                }
                else if(color[x]==color[node])
                {
                    return false;
                }
            }
        // }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[])
	{
	    vector<int>color(V,-1);
	   //int color[V];
    //   memset(color,-1,sizeof color);
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            color[i]=1;
	            if(!check(i,V,adj,color))
	            {
	                return false;
	            }
	        }
	    }
	    return true;
	    // Code here
	}
};
