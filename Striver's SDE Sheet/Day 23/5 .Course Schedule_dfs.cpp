// Error Arises due to undirected graph traversal 

// using directed graph 
// tc : o(n+e)
// sc : o(n+e) + o(n) + o(n)
class Solution 
{
public:
    
    bool dfs_cycle(int node, vector<int>adj[] ,vector<int>&vis,vector<int>&dfs_vis)
    {
        vis[node] = 1;
        dfs_vis[node] = 1;
        for(auto x : adj[node])
        {
            if(!vis[x])
            {
                vis[x]=1;
                dfs_vis[x] = 1;
                if(dfs_cycle(x,adj,vis,dfs_vis))
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
    
    bool canFinish(int numCourses, vector<vector<int>>& pre)
    {
        int n = numCourses;
        
        vector<int> vis(n,0);
        vector<int> dfs_vis(n,0);
        
        vector<int> adj[n];
        
        for(auto x : pre)
        {
            adj[x[1]].push_back(x[0]);
        }
        
        for(int i = 0;i<n;i++)
        {
            if(!vis[i])
            {
                if( dfs_cycle(i,adj,vis,dfs_vis))
                {
                    return false;
                }
            }
            
        }
        return true;
    }
};





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
