class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    // using BFS 
    bool checkforcycle(int i,vector<int>&visited,vector<int>adj[])
    {
        queue<pair<int,int>>q;
        q.push({i,-1});
        visited[i]=1;
        
        while(!q.empty())
        {
            int node=q.front().first;
            int par=q.front().second;
            q.pop();
            
            for(auto it:adj[node])
            {
                if(!visited[it])
                {
                    q.push({it,node});
                    visited[it]=1;
                }
                else if(par!=it)
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    
//     using DFS 
    bool checkforcycle(int node,int parent,vector<int>vis,vector<int>adj[])
    {
        vis[node]=1;
        for(auto x:adj[node])
        {
            if(vis[x]==0)
            {
                if(checkforcycle(x,node,vis,adj))
                {
                    return true;
                }
            }
            else if(x!=parent)
            {
                return true;
            }
        }
        return false;
    }
    
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<int>vis(V+1,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(checkforcycle(i,-1,vis,adj))
                {
                    return true;
                }
            }
        }
        return false;
        // Code here
    }
};
