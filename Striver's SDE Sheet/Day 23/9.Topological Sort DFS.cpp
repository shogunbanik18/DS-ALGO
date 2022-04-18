// using dfs 
// tc : o(n+e)
// sc : o(n+e) + o(n) + o(n) + auxiliary stack space 
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void dfs_sort(int node, vector<int>&vis,vector<int>adj[],stack<int>&st)
	{
	    vis[node] =1;
	    
	    for(auto x : adj[node])
	    {
	        if(!vis[x])
	        {
	           // vis[x] = 1;
	           // st.push(x);
	           dfs_sort(x,vis,adj,st);
	        }
	    }
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>ans;
	    stack<int>st;
	    
	    vector<int>vis(V,0);
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs_sort(i,vis,adj,st);
	        }
	    }
	    
	    while(!st.empty())
	    {
	        auto a = st.top();
	        st.pop();
	        ans.push_back(a);
	    }
	    
	    return ans;
	}
};
