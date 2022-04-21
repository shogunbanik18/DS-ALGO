// // using bfs 
// Using Kahn's Algorithms
// tc : o(n+e)
// sc : o(n+e) + o(n)
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool isCyclic(int V, vector<int> adj[]) 
    {
        queue<int>q;
        vector<int> indegree(V,0);
        
        for(int i = 0;i<V;i++)
        {
            for(auto x:adj[i])
            {
                indegree[x]++;
            }
        }
        
        for(int i = 0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        int count = 0;
        while(!q.empty())
        {
            auto a = q.front();
            q.pop();
            count++;
            
            for(auto x : adj[a])
            {
                indegree[x]--;
                if(indegree[x] == 0)
                {
                    q.push(x);
                }
            }
        }
        
        if(count == V)
        {
            return false;
        }
        return true;
    }
};
