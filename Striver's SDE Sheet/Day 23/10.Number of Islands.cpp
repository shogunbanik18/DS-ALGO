// // // intuition : erase all the nearby islands when found one
// using dfs 
// class Solution 
// {
// public:
      
//     void dfs(int i,int j ,vector<vector<char>> &grid)
//     {
//         int m = grid.size();
//         int n = grid[0].size();
//         if(i<0 or j<0 or i>=m or j>=n or grid[i][j]=='0')
//         {
//             return;
//         }
//         grid[i][j]='0';
        
//         dfs(i-1,j,grid);
//         dfs(i+1,j,grid);
//         dfs(i,j+1,grid);
//         dfs(i,j-1,grid);
       
//     }
    
    
//     int numIslands(vector<vector<char>>& grid) 
//     {
//         int m = grid.size();
//         int n = grid[0].size();
//         int island = 0;
        
//         for(int i = 0;i<m;i++)
//         {
//             for(int j = 0;j<n;j++)
//             {
//                 if(grid[i][j]=='1')
//                 {
//                     island++;
//                     dfs(i,j,grid);
//                 }
//             }
//         }
        
//         return island;
//     }
// };



// // intuition : erase all the nearby islands when found one
// using bfs 
class Solution 
{
public:
      
    void bfs(int i,int j ,vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>>q;
        q.push({i,j});
        
        while(!q.empty())
        {
            auto a = q.front();
            q.pop();
            
            int cr = a.first;
            int cc = a.second;
            
            if(cc<0 or cr<0 or cr>=m or cc>=n or grid[cr][cc]=='0')
            {
                continue;
            }
            
            grid[cr][cc] = '0';
            
            q.push({cr-1,cc});
            q.push({cr+1,cc});
            q.push({cr,cc+1});
            q.push({cr,cc-1});
        }
       return ;
    }
    
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int island = 0;
        
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    island++;
                    bfs(i,j,grid);
                }
            }
        }
        
        return island;
    }
};





// intuition : erase all the nearby islands when found one 
// using simple recursion 
// traversing the island and marking it as visited 
// class Solution 
// {
// public:
    
//     void dfs(int i,int j ,vector<vector<char>> &grid)
//     {
//         int n = grid.size();
//         int m = grid[0].size();
//         if(i<0 or j<0 or i>=n or j>=m or grid[i][j]!='1')
//         {
//             return;
//         }
//         grid[i][j] = '2';
        
//         // Four directions 
//         dfs(i-1,j,grid);
//         dfs(i+1,j,grid);
//         dfs(i,j+1,grid);
//         dfs(i,j-1,grid);
//     }
    
//     int numIslands(vector<vector<char>>& grid)
//     {
//         int n = grid.size();
//         int m = grid[0].size();
        
//         int island = 0;
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j = 0;j<m;j++)
//             {
//                 if(grid[i][j]=='1')
//                 {
//                     dfs(i,j,grid);
//                     island++;
//                 }
//             }
//         }
        
//         return island;
//     }
// };
