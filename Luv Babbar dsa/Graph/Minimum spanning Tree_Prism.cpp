class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    // 	tc:O(NlogN)
	int prims_algo(int src,int n,vector<vector<int>>adj[])
	{
	    int key[n];
	    bool mstset[n];
	    for(int i=0;i<n;i++)
	    {
	        key[i]=INT_MAX;
	        mstset[i]=false;
	    }
	    key[src]=0;
	    
	   // using heap data structure 
	   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	   pq.push({key[src],src});
	   
	   while(!pq.empty())
	   {
	       int u=pq.top().second;
	       pq.pop();
	       mstset[u]=1;
	       
	       for(auto i :adj[u])
	       {
	           int v=i[0];
	           int weight=i[1];
	           if(mstset[v]==0 and weight<key[v])
	           {
	               key[v]=weight;
	               pq.push({key[v],v});
	           }
	       }
	   }
	   
	   int sum=0;
	   for(int i=0;i<n;i++)
	   {
	       sum+=key[i];
	   }
	   return sum;
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        return prims_algo(0,V,adj);
        // code here
    }
};



// gdb 
#include<bits/stdc++.h>
using namespace std;

// tc: O(N^2)
// int main()
// {
//     int N,m;
//     cin>>N>>m;
//     vector<pair<int,int>>adj[N];
    
//     int a,b,wt;
//     for(int i=0;i,m;i++)
//     {
//         cin>>a>>b>>wt;
//         adj[a].push_back(make_pair(b,wt));
//         adj[a].push_back(make_pair(a,wt));
//     }
    
//     int parent[N];
//     int key[N];
//     bool mstSet[N];
    
//     for(int i=0;i<N;i++)
//     {
//         key[i]=INT_MAX;
//         mstSet[i]=false;
//         parent[i]=-1;
//     }
    
//     key[0]=0;
//     parent[0]=-1;
    
//     for(int count=0;count<N-1;count++)
//     {
//         int mini=INT_MAX;
//         int u;
//         for(int v=0;v<N;v++)
//         {
//             if(mstSet[v]==false and key[v]<mini)
//             {
//                 mini=key[v];
//                 u=v;
//             }
//         }
//         mstSet[u]=true;
        
//         for(auto x:adj[u])
//         {
//             int v=x.first;
//             int wt=x.second;
//             if(mstSet[v]==false and wt<key[v])
//             {
//                 parent[v]=u,key[v]=wt;
//             }
//         }
//     } 
    
//     for(int i=1;i<N;i++)
//     {
//         cout<<parent[i]<<" "<<i<<"\n";
//     }
//     return 0;
// }

// tc :O(NlogN)
// using heap data structure 
int main()
{
    int N,m;
    cin>>N>>m;
    vector<pair<int,int>>adj[N];
    
    int a,b,wt;
    for(int i=0;i,m;i++)
    {
        cin>>a>>b>>wt;
        adj[a].push_back(make_pair(b,wt));
        adj[a].push_back(make_pair(a,wt));
    }
    
    int parent[N];
    int key[N];
    bool mstSet[N];
    
    for(int i=0;i<N;i++)
    {
        key[i]=INT_MAX;
        mstSet[i]=false;
        parent[i]=-1;
    }
    
    // minimal priority queue 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greter<pair<int,int>>>pq;
    
    key[0]=0;
    parent[0]=-1;
    pq.push({0,0});
    
    for(int count=0;count<N-1;count++)
    {
        int u=pq.top().second;
        pq.pop();
        mstSet[u]=true;
        
        for(auto x:adj[u])
        {
            int v=x.first;
            int wt=x.second;
            if(mstSet[v]==false and wt<key[v])
            {
                parent[v]=u;
                pq.push({key[v],v});
                key[v]=wt;
            }
        }
    } 
    
    for(int i=1;i<N;i++)
    {
        cout<<parent[i]<<"_"<<i<<"\n";
    }
    return 0;
}
