// Greedy Approach 
// tc: o(NlogN)
// sc:O(1)

bool compare(vector<int>&a,vector<int>&b)
{
    return a[1]<b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        int n=points.size();
        if(points.size()==0)
        {
            return 0;
        }
        
        // sorting 
        sort(points.begin(),points.end(),compare);
        int end=points[0][1];
        int arrows=1;
        for(int i=1;i<n;i++)
        {
            if(points[i][0]>end)
            {
                arrows++;
                end=points[i][1];
            }
        }
        return arrows;
    }
};


