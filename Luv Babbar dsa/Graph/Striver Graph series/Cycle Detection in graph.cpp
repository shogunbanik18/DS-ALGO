// gfg 
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
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
    
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<int>visited(V+1,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(checkforcycle(i,visited,adj))
                {
                    return true;
                }
            }
        }
        return false;
        // Code here
    }
};


// striver code 
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool checkforcycle(int i,int V,vector<int>adj[],vector<int>&visited,)
    {
        queue<pair<int,int>>q;
        q.push({s,-1});
        visited[s]=true;
        
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
                    visited[it]=true;
                }
                else if(par!=it)
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<int>visited(V+1,0);
        for(int i=1;i<=V;i++)
        {
            if(!visited[i])
            {
                if(checkforcycle(i,V,adj,visited))
                {
                    return true;
                }
            }
        }
        return false;
        // Code here
    }
};
