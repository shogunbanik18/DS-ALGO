class Solution {
public:
      // tc: O(N^2)
      //  sc: O(1)
      void swap1(vector<vector<int>>&matrix,int i,int j)
      {
          int temp=matrix[i][j];
          matrix[i][j]=matrix[j][i];
          matrix[j][i]=temp;
      }
      
//     void reverse1(vector<vector<int>>&matrix)
//     {
//         int n=matrix.size();
//         for(int i=0;i<n;i++)
//           {
             
              
//               // using 2 pointer approach
//               for(int j=0;j<n/2;j++)
//               {
//                   // swapping 
//                   int temp=0;
//                   temp=matrix[i][j];
//                   matrix[i][j]=matrix[i][n-1-j];
//                   matrix[i][n-1-j]=temp;
//               }
//           }
//     }
      void rotate(vector<vector<int>>& matrix)
      {
          int n=matrix.size();
          int m=matrix[0].size();
          // transpose of a matrix 
          for(int i=0;i<n;i++)
          {
              for(int j=i;j<m;j++)
              {
                  swap1(matrix,i,j);
              }
          }
          
         
          // reversing the individual row using stl
          for(int i=0;i<n;i++)
          {
              reverse(matrix[i].begin(),matrix[i].end());
          }
          
           // reversing the individual row using function defined 
          // reverse1(matrix);
      }
    
    // using extra space
//     tc: o(n^2)
    // sc : o(N^2)
//      void rotate(vector<vector<int>>& matrix)
//      {
//          int n=matrix.size();
//          int m=matrix[0].size();
//          vector<vector<int>>ans;
//          for(int j=0;j<m;j++)
//          {
//              vector<int>v;
//              for(int i=n-1;i>=0;i--)
//              {
//                  v.push_back(matrix[i][j]);
//              }
//              ans.push_back(v);
//          }
         
//          for(int i=0;i<n;i++)
//          {
//              for(int j=0;j<m;j++)
//              {
//                  matrix[i][j]=ans[i][j];
//              }
//          }
//      }
};
