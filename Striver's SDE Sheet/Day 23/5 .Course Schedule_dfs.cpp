// using dfs traversal
// tc : o(n+e)
// sc : o(n+e) + o(n) + o(n)
class Solution 
{
public:
    
    bool dfs(int node,int parent, vector<int>&vis ,vector<int> adj[])
    {
        if(vis[node]==1)
        {
            return true;
        }
        
        if(!vis[node])
        {
            vis[node] = 1;
            
            for(auto x : adj[node])
            {
               if(dfs(x ,node, vis, adj))
               {
                    return true;
               }
            }   
        }
        
        vis[node] = 2;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& pre) 
    {
        int n = numCourses;
        vector<int> adj[n];
        
        for(auto x : pre)
        {
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++)
        {
            // if there is cycle present the course1 cannot be completed before course 0  
            if(dfs(i,-1,vis,adj))
            {
                return false;
            }
        }
        
        return true;
    }
};
