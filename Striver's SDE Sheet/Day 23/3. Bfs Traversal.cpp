// Bfs Traversal using queue 
// tc : o(n+e)
// sc : o(n+e) + o(n) + o(n)
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    void bfs(int node, vector<int>&vis,vector<int>adj[], vector<int>&store)
    {
        queue<int>q;
        q.push(node);
        
        while(!q.empty())
        {
            auto a = q.front();
            q.pop();
            
            store.push_back(a);
            
            for(auto x : adj[a])
            {
                if(!vis[x])
                {
                    q.push(x);
                    vis[x] = 1;
                }
            }
        }
        
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<int>store;
        vector<int>vis(V+1,0);
        
        bfs(0,vis,adj,store);
        
        // for(int i=1;i<=V;i++)
        // {
        //     if(!vis[i])
        //     {
        //         bfs(i,vis,adj,store);
        //     }
        // }
        return store;
    }
};
