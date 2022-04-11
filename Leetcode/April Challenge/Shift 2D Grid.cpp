// // Brute Force 
// // tc : o(n^3)
// // sc : o(1)
// class Solution {
// public:
//     vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
//     {
//         int m = grid.size();
//         int n = grid[0].size();
        
//         vector<vector<int>>ans(m,vector<int>(n,0));
        
//         if(k==0)
//         {
//             return grid;
//         }
        
//         while(k--)
//         {
//             for(int i=0;i<m;i++)
//             {
//                 for(int j=0;j<n;j++)
//                 {
//                     if(j==0)
//                     {
//                         if(i!=0)
//                         {
//                             ans[i][j] = grid[i-1][n-1];
//                         }
//                         else
//                         {
//                             ans[i][j] = grid[m-1][n-1];
//                         }
//                     }
//                     else
//                     {
//                         ans[i][j] = grid[i][j-1];
//                     }
//                 }
//             }

//             for(int i=0;i<m;i++)
//             {
//                 for(int j=0;j<n;j++)
//                 {
//                     grid[i][j] = ans[i][j];
//                 }
//             }
//         }
//         return ans;
//     }
// };


// Brute Force 
// tc : o(n)
// sc : o(1)
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>ans =grid;
        
        for(int i=0;i<(n*m);i++)
        {
            int temp = (i+k)%(n*m);
            ans[temp/n][temp%n] = grid[i/n][i%n];
        }
        return ans;
    }
};
