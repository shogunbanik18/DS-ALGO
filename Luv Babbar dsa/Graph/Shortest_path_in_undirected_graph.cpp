#include<bits/stc++.h>
using namespace std;

// tc :O(N+E)
// SC : O(2N) 
void bfs(vector<int>adj[],int N,int src)
{
    vector<int>distance(N,INT_MAX);
    queue<int>q;
    
    distance[src]=0;
    q.push(src);
    
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        
        for(auto x: adj[node])
        {
            if(distance[node]+1<distance[x])
            {
                distance[x]=distance[node]+1;
                q.push(x);
            }
        }
    }
    
    for(int i=0;i<N;i++)
    {
        cout<<distance[i]<<" ";
    }
}
