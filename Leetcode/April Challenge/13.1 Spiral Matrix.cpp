// // Brute Force
// // tc : o(n^2)
// // sc : o(1)

// Brute Force 
// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) 
//     {
//         int m = matrix.size();
//         int n = matrix[0].size();
        
//         vector<int>v;
        
//         for(int i=0;i<n;i++)
//         {
//             v.push_back(matrix[0][i]);
//         }
        
//         // for(auto x :v)
//         // {
//         //     cout<<x<<" ";
//         // }
        
//         for(int i=1;i<m;i++)
//         {
//             v.push_back(matrix[i][n-1]);
//         }
        
//         for(int i = n-2;i>=0;i--)
//         {
//             v.push_back(matrix[m-1][i]);
//         }
        
//         for(int i= m-2;i>=1;i--)
//         {
//             v.push_back(matrix[i][0]);
//         }
        
//         for(int i=1;i<n-1;i++)
//         {
//             v.push_back(matrix[m-2][i]);
//         }
        
//         return v;
//     }
// };


// Brute Force
// tc : o(n^2)
// sc : o(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int r1 =0 ,r2 = m-1;
        int c1 =0 ,c2 = n-1;
        int dir = 1;
        
        vector<int>v;
        
        while(r1<=r2 and c1<=c2)
        {
            if(dir==1)
            {
                for(int i= c1 ;i<=c2 ;i++)
                {
                    v.push_back( matrix[r1][i]);
                }
                r1++;
                dir = 2;
            }
            
            else if(dir==2)
            {
                 for(int i= r1 ;i<=r2 ;i++)
                {
                    v.push_back( matrix[i][c2]);
                }
                c2--;
                dir = 3;
            }
            
            else if(dir==3)
            {
                 for(int i= c2 ;i>=c1 ;i--)
                {
                    v.push_back( matrix[r2][i]);
                }
                r2--;
                dir = 4;
            }
            
            else if(dir==4)
            {
                 for(int i= r2 ;i>=r1 ;i--)
                {
                    v.push_back( matrix[i][c1]);
                }
                c1++;
                dir = 1;
            }
        }
        
        return v;
    }
};
