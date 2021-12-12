class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    bool vis[1000]={false};
    void dfs(vector<int>adj[],vector<int>&v,int i)
    {
        if(vis[i]==false)
        {
            vis[i]=true;
            v.push_back(i);
            for(auto x:adj[i])
            {
                if(!vis[x])
                {
                    dfs(adj,v,x);
                }
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<int>v;
        dfs(adj,v,0);
        return v;
    }
};



// #include<bits/stdc++.h>
// using namespace std;

// // recursive way 
// class solution
// {
//     void dfs(int node,vector<int>&vis,vector<int>adj[],vector<int>&storedfs)
//     {
//         storedfs.push_back(node);
//         vis[node]=1;
//         for(auto x:adj[node])
//         {
//             if(!vis[x])
//             {
//                 dfs(x,vis,adj,storedfs);
//             }
//         }
//     }
    
//     public:
//     vector<int>dfsofgraph(int V,vector<int>adj[])
//     {
//         vector<int>storedfs;
//         vector<int>vis(V+1,0);
//         for(int i=1;i<=V;i++)
//         {
//             if(!vis[i])
//             {
//                 // dfs traversal
//                 dfs(i,vis,adj,storedfs);
//             }
//         }
//         return storedfs;
//     }
// };
