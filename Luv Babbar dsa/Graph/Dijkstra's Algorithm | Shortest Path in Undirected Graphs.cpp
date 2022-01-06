#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,source;
    cin>>n>>m;
    vector<pair<int,int>>g[n+1];
    
 
    for(int i=0;i<n;i++)
    {
        int a,b,wt;
        cin>>a>>b>>wt;
        g[a].push_back(make_pair(b,wt));
        g[b].push_back(make_pair(a,wt));
    }
    
    cin>>source;
    // min heap 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>distance(n+1,INT_MAX);
    
    distance[source]=0;
    pq.push(make_pair(0,source));
    
    while(!pq.empty())
    {
        int dist1=pq.top().first;
        int prev=pq.top().second;
        pq.pop();
        
        for(auto x :g[prev])
        {
            int next=x.first;
            int nextdist=x.second;
            if(distance[next]>dist1+nextdist)
            {
                distance[next]=distance[prev]+nextdist;
                pq.push(make_pair(distance[next],next));
            }
        }
    }
    
    // cout<"The distance from source "<<source<<",are : "<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<distance[i]<<" ";
    }
    return 0;
}



// gfg 

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dis(V,INT_MAX);
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dis[S]=0;
        pq.push(make_pair(0,S));
        
        while(!pq.empty())
        {
            int next=pq.top().first;
            int prev=pq.top().second;
            pq.pop();
            
            for(auto it :adj[prev])
            {
                int next=it[0];
                int nextdis=it[1];
                if(dis[next]>dis[prev]+nextdis)
                {
                    dis[next]=dis[prev]+nextdis;
                    pq.push(make_pair(dis[next],next));
                }
            }
        }
        return dis;
     
        // using normal queue 
        vector<int>dist(V,INT_MAX);
        queue<int>q;
        
        dist[S]=0;
        q.push(S);
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto x :adj[node])
            {
                int nextNode = x[0];
                int nextDist=x[1];
                if(dist[node]+nextDist<dist[nextNode])
                {
                    dist[nextNode]=dist[node]+nextDist;
                    q.push(nextNode);
                }
            }
        }
        return dist;
        // Code here
    }
};
