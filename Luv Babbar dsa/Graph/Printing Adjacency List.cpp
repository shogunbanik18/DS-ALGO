class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[])
    {
        vector<vector<int>>res;
        for(int i=0;i<V;i++)
        {
            vector<int>temp;
            temp.push_back(i);
            for(auto x:adj[i])
            {
                temp.push_back(x);
                res.push_back(temp);
            }
        }
        return res;
        // Code here
    }
};
