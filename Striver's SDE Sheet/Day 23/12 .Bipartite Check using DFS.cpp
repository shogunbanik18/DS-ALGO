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
