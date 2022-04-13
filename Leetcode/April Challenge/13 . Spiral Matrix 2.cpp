// class Solution {
// public:
//     vector<vector<int>> generateMatrix(int n)
//     {
//         vector<vector<int>>ans(n,vector<int>(n,0));
        
//         int row  =0;
//         int col = 0;
//         int k=0;
        
//         for(int col=0;col<n;col++)
//         {
//             ans[row][col] = k+1;
//             k++;
//         }
        
//         for(int row = 1;row < n; row++)
//         {
//             ans[row][n-1] = k+1;
//             k++;
//         }
        
//         for(int col = n-2; col>=0; col --)
//         {
//             ans[n-1][col] = k+1;
//             k++;
//         }
        
//         for(int row = n-2; row> 0;row--)
//         {
//             ans[row][0] = k+1;
//             k++;
//         }
        
        
//         return ans;
        
//     }
// };

// tc : o(n^2)
// sc : o(1)

class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>>ans(n,vector<int>(n,0));
        
        int r1 = 0, r2 =n-1;
        int c1 = 0, c2= n-1;
        int k=1;
        
        while(r1<=r2 and c1<=c2)
        {
            for(int i=c1;i<=c2;i++)
            {
                ans[r1][i] = k;
                k++;
            }
            
            for(int i = r1+1;i<=r2;i++)
            {
                ans[i][c2] = k;
                k++;
            }
            
            if(r1<r2 and c1<c2)
            {
                for(int i = c2-1;i>c1;i--)
                {
                    ans[r2][i] = k;
                    k++;
                }
                
                for(int i = r2;i>r1;i--)
                {
                    ans[i][c1] = k;
                    k++;
                }
            }
            
            r1++;
            r2--;
            c1++;
            c2--;
            
        }
        
        return ans;
    }
};
