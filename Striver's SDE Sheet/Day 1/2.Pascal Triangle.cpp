class Solution {
public:
    // tc : O(n*n)
    // sc : o(N)
//     vector<vector<int>> generate(int numRows) 
//     {
//         vector<vector<int>>ans(numRows);
//         for(int i=0;i<numRows;i++)
//         {
//             ans[i].resize(i+1);
//             // setting first and last value as 1
//             ans[i][0]=ans[i][i]=1;
            
            
//             for(int j=1;j<i;j++)
//             {
//                 ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
//             } 
//         }
//         return ans;
//     }
    
    
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++)
        {
            vector<int>rows(i+1,1);
            for(int j=1;j<i;j++)
            {
                rows[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(rows);
        }
        return ans;
    }
};
