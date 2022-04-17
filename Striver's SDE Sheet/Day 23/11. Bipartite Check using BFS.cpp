// using col array as visted array 
// tc : o(n+e)
// sc : o(n+e) + o(n) + o(n)
class Solution {
public:

    bool checkbipartite(int node, vector<int>&col, vector<int> adj[])
    {
        queue<int>q;
           
        col[node] = 1;
        q.push(node);
        
        while(!q.empty())
        {
            auto a = q.front();
            q.pop();
            
            for(auto x : adj[a])
            {
                if(col[x]==-1)
                {
                    col[x]=1 - col[a];
                    q.push(x);
                }
                
                else if(col[x]==col[a])
                {
                    return false;
                }
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
