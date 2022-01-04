class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    // using bfs 
    // tc: O(N*N)*4
    // sc:O(N*N)
    bool checkValid(int i,int j,int row ,int col)
    {
        if(i<0 or j<0 or i>=row or j>=col)
        {
            return false;
        }
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid)
    {
        int row=grid.size();
        int col =grid[0].size();
        
        queue<pair<int,int>>q;
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
            int size=q.size();
            bool flag=false;
            for(int k=0;k<size;k++)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(checkValid(i+1,j,row,col) and grid[i+1][j]==1)
                {
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                    flag=true;
                }
                
                if(checkValid(i-1, j, row, col) && grid[i-1][j]==1)
                   {
                       grid[i-1][j]=2;
                       q.push({i-1,j});
                       flag=true;
                   }
                
                 if(checkValid(i,j+1,row,col) && grid[i][j+1]==1)
               {
                   grid[i][j+1]=2;
                   q.push({i,j+1});
                   flag=true;
               }
                
                if(checkValid(i, j-1, row, col) && grid[i][j-1]==1)
                   {
                       grid[i][j-1]=2;
                       q.push({i,j-1});
                       flag=true;
                   }   
            }
            if(flag==true)
            {
                count++;
            }
        }
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return count;
        // Code here
    }
};
