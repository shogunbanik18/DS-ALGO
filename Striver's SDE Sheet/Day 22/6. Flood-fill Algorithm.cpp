// // using dfs recursion
// // tc : o(2^n)
// // sc : o(1) + stack space
class Solution 
{
public:
    
    void dfs(vector<vector<int>>& grid , int sr ,int sc ,int newColor,int x)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        if(sr<0 or sr>=m or sc<0 or sc>=n or grid[sr][sc]!=x or grid[sr][sc] == newColor)
        {
            return;
        }
        
        grid[sr][sc] = newColor;
        
        dfs(grid, sr-1 ,sc,newColor,x);
        dfs(grid, sr+1 ,sc,newColor,x);
        dfs(grid, sr,sc-1,newColor,x);
        dfs(grid, sr,sc+1,newColor,x);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int x = image[sr][sc];
        dfs(image,sr,sc,newColor,x);
        return image;
    }
};

// using Bfs Traversal (Queue)
// tc :  O(V + E)
// sc : o(1) + stack space
class Solution 
{
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int m = image.size();
        int n = image[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n,0));
        queue< pair<int,int>> q;
            
        q.push({sr,sc});
        vis[sr][sc]=1;
        
        while(!q.empty())
        {
            auto i = q.front().first;
            auto j = q.front().second;
            q.pop();
            
            // up 
            if(i-1>=0 and image[i-1][j] == image[i][j] and vis[i-1][j]==0)
            {
                vis[i][j]=1;
                q.push({i-1,j});
            }
            
            // down
            if(i+1<m and image[i+1][j] == image[i][j] and vis[i+1][j]==0)
            {
                vis[i][j]=1;
                q.push({i+1,j});
            }
            
            // left
            if(j-1>=0 and image[i][j-1] == image[i][j] and vis[i][j-1]==0)
            {
                vis[i][j]=1;
                q.push({i,j-1});
            }
            
            // right
            if(j+1<n and image[i][j+1] == image[i][j] and vis[i][j+1]==0)
            {
                vis[i][j]=1;
                q.push({i,j+1});
            }
            
            image[i][j] = newColor;
        }
        
        return image;
    }
};
