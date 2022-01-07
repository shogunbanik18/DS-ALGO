// Using DFS 
// TC: O(N*M)
// SC:(N*M)
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int i,int j,int visited[][501],vector<vector<char>>&grid,int n,int m)
    {
        if(i<0 or j<0 or i>=n or j>=m)
        {
            return;
        }
        if(grid[i][j]=='0' or visited[i][j]==1)
        {
            return;
        }
        if(!visited[i][j])
        {
            visited[i][j]=1;
            dfs(i,j+1,visited,grid,n,m);
            dfs(i,j-1,visited,grid,n,m);
            dfs(i+1,j,visited,grid,n,m);
            dfs(i-1,j,visited,grid,n,m);
            dfs(i+1,j+1,visited,grid,n,m);
            dfs(i+1,j-1,visited,grid,n,m);  
            dfs(i-1,j-1,visited,grid,n,m);
            dfs(i-1,j+1,visited,grid,n,m);
        }
    }
    
    // using dfs 
    int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int visited[501][501];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                visited[i][j]=0;
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] and grid[i][j]=='1') 
                {
                    dfs(i,j,visited,grid,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};
