// // using Brute Force  
// // tc : o(n*n)
// // sc : o(1)
// class Solution 
// {
// public:
//     int trap(vector<int>& height) 
//     {
//         int n = height.size();
//         int ans =0;
        
//         for(int i=0;i<n;i++)
//         {
//              int j=i;
//              int leftmax=0;
//              int rightmax=0;
            
//              while(j>=0)
//              {
//                  leftmax = max(height[j] , leftmax);
//                  j--;
//              }
            
//              j=i;
//              while(j<n)
//              {
//                  rightmax = max(height[j] , rightmax);
//                  j++;
//              }
            
//              ans += min(leftmax,rightmax) -height[i]; 
            
//         }
//         return ans;
//     }
// };


// // using the concept of array preprocessing 
// // tc : o(n) + o(n) + o(n)
// // sc : o(n) + o(n)
// class Solution 
// {
// public:
//     int trap(vector<int>& height) 
//     {
//         int n = height.size();
        
//         vector<int>left(n,0),right(n,0);
        
//         // preprocessing the left maximum 
//         left[0] = height[0];
//         for(int i=1;i<n;i++)
//         {
//             left[i] = max(left[i-1],height[i]);
//         }
        
//         // Debug
//         // for(auto x : left)
//         // {
//         //     cout<<x<<" ";
//         // }
//         // cout<<endl;
        
//         // preprocessing the Right maximum
//         int j = n-1;
//         right[n-1] = height[n-1];
//         for(int j=n-2;j>=0;j--)
//         {
//             right[j] = max(right[j+1],height[j]);
//         }
        
//         // Debug
//         // for(auto x : right)
//         // {
//         //     cout<<x<<" ";
//         // }
        
//         int ans =0;
        
//         for(int i=0;i<n;i++)
//         {
//             ans += min(left[i],right[i]) - height[i]; 
//         }
        
//         return ans;
        
//     }
// };


// Optimised approach using two pointers
// tc : o(n) + o(n) + o(n)
// sc : o(1)
class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        int l =0;
        int r = n-1;
        int ans =0,leftmax=0,rightmax=0;
        
        while(l<=r)
        {
            if(height[l]<=height[r])
            {
                if(height[l]>=leftmax)
                {
                    leftmax = height[l];
                }
                
                else
                {
                    ans += leftmax - height[l];
                }
                l++;
            }
            
            else
            {
                if(height[r]>=rightmax)
                {
                    rightmax = height[r];
                }
                
                else
                {
                    ans += rightmax - height[r];
                }
                 r--;
            }
        }
        
        return ans;
    }
};
