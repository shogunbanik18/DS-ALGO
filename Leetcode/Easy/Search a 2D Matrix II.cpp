class Solution {
public:
    // Brute force 
    // tc:o(n*m)
    // sc:o(1)
    // bool searchMatrix(vector<vector<int>>& matrix, int target) 
    // {
    //     int n=matrix.size();
    //     int m=matrix[0].size();
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             if(matrix[i][j]==target)
    //             {
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
    
//     Better solution 
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0;
        int j=m-1;
        while(i<n and j>=0)
        {
            if(matrix[i][j]==target)
            {
                return true;
            }
            if(matrix[i][j]>target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
    
    // using binary search in the matrixwithout extra space 
    // tc:o(logm)
    // sc:o(n)
//     bool searchMatrix(vector<vector<int>>& matrix, int target) 
//     {
//         int n=matrix.size();
//         int m=matrix[0].size();
        
//          int low=0;
//          int high= (m*n)-1;
//          while(low<=high)
//          {
//              int mid=(low+high)/2;
//              if(matrix[mid/m][mid%m]==target)
//              {
//                  return true;
//              }
//              else if(matrix[mid/m][mid%m]<target)
//              {
//                  low=mid+1;
//              }
//              else
//              {
//                  high=mid-1;
//              }
//          }
//         return false;
//     }
};
