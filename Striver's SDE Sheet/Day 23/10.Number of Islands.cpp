// class Solution {
// public:
    
//     void dfs(int i,int j ,vector<vector<char>> &grid,int count)
//     {
//         int n = grid.size();
//         int m = grid[0].size();
//         if(i==0 and j==0)
//         {
//             return;
//         }
        
        
//         if(grid[i][j]=='1' and grid[i-1][j]=='0' and grid[i+1][j]=='0' and grid[j-1][j]=='0' and grid[i][j+1]=='0')
//         {
//             count++;
//         }
        
//         if(i-1>=0 and grid[i][j]=='1')
//             dfs(i-1,j,grid,count);
        
//         if(j-1>=0 and grid[i][j]=='1')
//             dfs(i,j-1,grid,count);
        
//         if(i+1<n and grid[i][j]=='1')
//             dfs(i+1,j,grid,count);
        
//         if(j+1<m and grid[i][j]=='1')
//             dfs(i-1,j,grid,count);
    
//     }
    
//     int numIslands(vector<vector<char>>& grid)
//     {
//         int n = grid.size();
//         int m = grid[0].size();
        
//         int count = 0;
//         dfs(n-1,m-1,grid,count);
//         return count;
//     }
// };


// intuition : erase all the nearby islands when found one 
// using simple recursion 
class Solution 
{
public:
    
    void dfs(int i,int j ,vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]=='0')
        {
            return;
        }
        grid[i][j] = '0';
        
        // Four directions 
        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    
    int numIslands(vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        int island = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    island++;
                    dfs(i,j,grid);
                }
            }
        }
        
        return island;
    }
};
