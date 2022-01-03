class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
    // 	using dfs 
    // DAG Diected acyclic graph
    
// 	void dfstopo(int node,vector<int>&visited,vector<int> adj[],stack<int>&st)
// 	{
// 	    visited[node]=1;
// 	    for(auto x : adj[node])
// 	    {
// 	        if(!visited[x])
// 	        {
// 	            dfstopo(x,visited,adj,st);
// 	        }
// 	    }
// 	    st.push(node);
// 	}

// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    stack<int>st;
// 	    vector<int>visited(V,0);
// 	    for(int i=0;i<V;i++)
// 	    {
// 	        if(visited[i]==0)
// 	        {
// 	            dfstopo(i,visited,adj,st);
// 	        }
// 	    }
	    
// 	    vector<int>v;
// 	    while(!st.empty())
// 	    {
// 	        v.push_back(st.top());
// 	        st.pop();
// 	    }
// 	    return v;
// 	    // code here
// 	}

    // using kahns Algorithm 
    // using bfs 
    // concept of indegree 
    vector<int> topoSort(int V, vector<int> adj[])
    {
    	   queue<int>q;
    	   vector<int> indegree(V,0);
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
    	   
    	   vector<int>ans;
    	   while(!q.empty())
    	   {
    	       int node=q.front();
    	       q.pop();
    	       ans.push_back(node);
    	       for(auto x:adj[node])
    	       {
    	           indegree[x]--;
    	           if(indegree[x]==0)
    	           {
    	               q.push(x);
    	           }
    	       }
    	   }
    	 return ans;
    }
};
