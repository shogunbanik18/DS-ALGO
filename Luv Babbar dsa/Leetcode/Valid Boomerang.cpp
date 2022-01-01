#math
#geometry 
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) 
    {
        // base case 
        if(points[0]==points[1] or points[1]==points[2] or points[2]==points[0] )
        {
            return false;
        }
        
        int f=points[0][0]*points[1][1]+points[1][0]*points[2][1]+points[2][0]*points[0][1];
        int s=points[0][1]*points[1][0]+points[1][1]*points[2][0]+points[2][1]*points[0][0];
        int area=abs(f-s);
        return area!=0;
    }
};
