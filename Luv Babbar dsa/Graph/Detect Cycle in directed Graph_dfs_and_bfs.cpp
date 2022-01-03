class Solution {
  public:
    // Function to detect cycle in a directed graph.
    // using dfs 
    bool checkcycle(int node,vector<int>adj[],vector<int>&visited,vector<int>&dfs)
    {
        visited[node]=1;
        dfs[node]=1;
        
        for(auto x : adj[node])
        {
            if(!visited[x])
            {
                if(checkcycle(x,adj,visited,dfs))
                {
                    return true;
                }
            }
             else if(dfs[x])
                {
                    return true;
                }
        }
        dfs[node]=0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) 
    {
        vector<int>visited(V,0);
        vector<int>dfs(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(checkcycle(i,adj,visited,dfs))
                {
                    return true;
                }
            }
        }
        return false;
        // code here
    }
};


    // using bfs
    // kahn's algorithm 
    // valid for DAG directed acyclic graph 
    bool isCyclic(int V, vector<int> adj[]) 
    {
        queue<int>q;
        vector<int>indegree(V,0);
        
        for(int i=0;i<V;i++)
        {
            for(auto x: adj[i])
            {
                indegree[x]++;
            }
        }
        
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        int count=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count++;
            for(auto x:adj[node])
            {
                indegree[x]--;
                if(indegree[x]==0)
                {
                    q.push(x);
                }
            }
        }
        
        if(count==V)
        {
            return false;
        }
        else 
        {
            return true;
        }
    }
