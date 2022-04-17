// gfg 
// using col array as visted array dfs traversal 
// tc : o(n+e)
// sc : o(n+e) + o(n) + o(n)
class Solution {
public:

    bool checkbipartite(int node, vector<int>&col, vector<int> adj[])
    {
        if(col[node]==-1)
        {
            col[node] =1;
        }
           
        
        for(auto x :adj[node])
        {
            if(col[x]==-1)
            {
                col[x] = 1 -col[node];
                if(!checkbipartite(x,col,adj))
                {
                    return false;
                }
                
            }
            
            else if(col[x] == col[node])
            {
                return false;
            }
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[])
	{
	    vector<int>col(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(col[i]==-1)
	        {
	            if(!checkbipartite(i,col,adj))
	            {
	                return false;
	            }
	        }
	    }
	    return true;
	}
};


// Leetcode 
// using Dfs
// tc : o(n+e)
// sc : o(n+e) + o(n) + o(n)
class Solution 
{
public:
    // using dfs taversal 
    bool dfs(int node ,vector<vector<int>>& graph , vector<int>&col)
    {
        if(col[node]==-1)
        {
               col[node] =1;
         }
           
        for(auto x : graph[node])
        {
            if(col[x]==-1)
            {
                col[x] = 1 - col[node];
                if(!dfs(x,graph,col))
                {
                    return false;
                }
            }
              
            else if(col[x] == col[node])
            {
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        int m = graph[0].size();
        
//         vector<int> adj[n];
//         for(int i = 0;i<n;i++)
//         {
//             for(int j = 0;j<m;j++)
//             {
//                 adj[i].push_back(j);
//                 adj[j].push_back(i);
//             }
//         }
        
        vector<int> col(n,-1);
        for(int i =0;i<n;i++)
        {
            if(col[i]==-1)
            {
                col[i] = 1;
                if(!dfs(i,graph,col))
                {
                    return false;
                }
            }
        }
        return true;
    }
};


