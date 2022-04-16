// gfg 
// using dfs traversal algorithm
// tc : o(n+e)
// sc :o(n+e) + o) + o(n) + o(n)
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool check_dfs(int node ,int parent , vector<int>& vis ,vector<int>adj[])
    {
        vis[node] = 1;
        
        for(auto x : adj[node])
        {
            if(!vis[x])
            {
                if(check_dfs(x,node,vis,adj))
                {
                    return true;
                }
            }
            
            else if( x !=parent)
            {
                return true;
            }
        }
        
    }
    
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<int>vis(V+1,0);
        
        for(int i = 0;i<V;i++)
        {
            if(!vis[i])
            {
                if(check_dfs(i,-1,vis,adj))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};
