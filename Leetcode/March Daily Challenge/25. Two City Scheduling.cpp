// Greedy Approach 
// tc: o(nlogn)
// sc : o(1)

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        int n = costs.size();
        int sum=0;
        
        vector<int>diff;
        
        for(int i=0;i<n;i++)
        {
            int a = costs[i][0];
            sum += a;
            
            int dif1 = costs[i][1]- costs[i][0];
            diff.push_back(dif1);
        }
        
        // debug 
        // cout<<sum<<endl;
        // for(auto x : diff )
        // {
        //     cout<<x<<" ";
        // }
        
        sort(diff.begin(),diff.end());
        
//         for(auto x : diff )
//         {
//             cout<<x<<" ";
//         }
        
        for(int i=0;i< n/2;i++)
        {
            sum += diff[i];
        }
        
        return sum;
    }
};
