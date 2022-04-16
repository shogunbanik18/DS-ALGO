// gfg
// tc : o(n+e)
// sc : o(n+e) + o(n) + o(n)
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool check(int node ,vector<int>& vis ,vector<int>adj[])
    {
        queue< pair< int,int>> q;
        vis[node] = 1;
        q.push({node,-1});
        
        while(!q.empty())
        {
            auto a = q.front();
            q.pop();
            
            int root   = a.first;
            int parent = a.second;
            
            for(auto x : adj[root])
            {
                if(!vis[x])
                {
                    q.push({x,root});
                    vis[x]=1;
                }
                
                else if(parent !=x)
                {
                    return true;
                }
                  
            }
            return false;
        }
        
    }
    
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<int>vis(V+1,0);
        
        for(int i = 0;i<V;i++)
        {
            if(!vis[i])
            {
                if(check(i,vis,adj))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};
