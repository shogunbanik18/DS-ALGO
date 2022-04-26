// classical problem on graph 
// concept  : minimal spanning tree + prism alog + kruskals algo
// tc : 
class Solution
{
public:
    
    int find(int src ,int n,vector<vector<int>>& points)
    {
        vector<int>key(n,INT_MAX);
        vector<int>parent(n,-1);
        vector<bool>mst(n,false);
        
        // conversion to adj[] list 
        vector<pair<int,int>>adj[n];
        
        for(int i=0;i<n;i++)
        {
           for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    adj[i].push_back({j,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
                    
                }
            }
        }
        
        
        key[src] = 0;
        
        priority_queue< pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>> > pq;
        pq.push({key[src],src});
        
        while(!pq.empty())
        {
            auto u = pq.top().second;
            pq.pop();
            
            mst[u] = true;
            
            for(auto x : adj[u])
            {
                int a = x.first;
                int weight = x.second;
                if(mst[a]==false and weight<key[a])
                {
                    key[a] = weight;
                    pq.push({key[a],a});
                }
            }
        }
            
        int sum = 0;
        for(auto x : key)
        {
            sum +=x;
        }
        return sum;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        return find(0,n,points);
    }
};
