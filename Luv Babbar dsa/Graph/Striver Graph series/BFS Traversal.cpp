class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
                vector<int>bfs;
                vector<int>vis(V,0);
        

                // bfs traversal algorithm 
                queue<int>q;
                q.push(0);
                vis[0]=1;
                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();
                    bfs.push_back(node);
                    
                    for(auto it: adj[node])
                    {
                        if(!vis[it])
                        {
                            q.push(it);
                            vis[it]=1;
                        }
                    }
                }
        return bfs;
        // Code here
    }
};


// for graph with different componenets 
// #include<bits/stdc++.h>
// using namesapce std;

// class solution
// {
//     public:
//     vector<int>bfsofgraph(int V,vector<int>adj[])
//     {
//         vector<int>bfs;
//         vector<int>vis(V+1,0);
        
//         // basic step for all traversal 
//         for(int i=0;i<=V;i++)
//         {
//             if(!vis[i])
//             {
//                 queue<int>q;
//                 q.push(i);
//                 vis[i]=1;
//                 while(!q.empty())
//                 {
//                     int node=q.front();
//                     q.pop();
//                     bfs.push_back(node);
                    
//                     for(auto x :adj[node])
//                     {
//                         if(!vis[x])
//                         {
//                             q.push(x);
//                             vis[x]=1;
//                         }
//                     }
//                 }
//             }
//         }
//         return bfs;
//     }
// };
