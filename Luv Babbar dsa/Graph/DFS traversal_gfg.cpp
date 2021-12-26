// gfg
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    bool vis[1000]={false};
    void dfs(vector<int> adj[],vector<int>&storedfs,int i)
    {
        if(vis[i]==false)
        {
            vis[i]=true;
            storedfs.push_back(i);
            for(auto x:adj[i])
            {
                if(!vis[x])
                {
                    dfs(adj,storedfs,x);
                }
            }
        }
    }
    
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<int>storedfs;
        dfs(adj,storedfs,0);
        return storedfs;
        // Code here
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
