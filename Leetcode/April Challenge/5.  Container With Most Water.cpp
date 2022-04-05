// using 2 pointer appraoch 
// tc : o(n) + o(n)
// sc : o(1)
class Solution
{
public:
    int maxArea(vector<int>& height) 
    {
        int n = height.size();
        
        int maxi = INT_MIN;
        int i= 0;
        int j = n-1;
        
        while(i<=j)
        {
            int area = (j-i) * min(height[i] , height[j]);
           
            
//             if(area > maxi)
//             {
//                 i++;
//             }
            
//             else
//             {
//                 j--;
//             }
                
            if(height[i] < height[j] )
            {
                i++;
            }
            
            else
            {
                j--;
            }
            
            maxi = max(area,maxi);
            cout<<maxi<<" ";
        }
        
        return maxi;
    }
};
