// tc : o(n+e)
// sc : o(n+e) + o(n + o(n)
class Solution 
{
  public:
    // Function to detect cycle in a directed graph.
    
    bool cycle_dfs(int node , vector<int>&vis,vector<int>&dfs_vis, vector<int>adj[])
    {
        vis[node]=1;
        dfs_vis[node]=1;
        
        for(auto x : adj[node])
        {
            if(!vis[x])
            {
                vis[x] = 1 ;
                dfs_vis[x]=1;
                
                if(cycle_dfs(x,vis,dfs_vis,adj))
                {
                    return true;
                }
            }
            
            else if(dfs_vis[x])
            {
                return true;
            }
        }
        
        // backtracking step 
        dfs_vis[node] = 0;
        
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) 
    {
        vector<int>vis(V,0);
        vector<int>dfs_vis(V,0);
        
        for(int i = 0;i<V;i++)
        {
            if(!vis[i])
            {
                if(cycle_dfs(i,vis,dfs_vis,adj))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};
