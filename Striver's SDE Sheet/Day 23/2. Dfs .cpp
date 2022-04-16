class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int node ,vector<int>&vis, vector<int> adj[] ,vector<int>&store)
    {
        store.push_back(node);
        vis[node] = 1;
        
        for(auto x : adj[node] )
        {
            if(!vis[x])
            {
                dfs(x,vis,adj,store);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int>store ;
        vector<int> vis (V+1,0);
        
        dfs(0,vis,adj,store);
        
        // for(int i = 1;i<=V;i++)
        // {
        //     if(!vis[i])
        //     {
        //         dfs(i,vis,adj,store);
        //     }
        // }
        
        return store;
    }
};
