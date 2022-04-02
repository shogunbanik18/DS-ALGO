// use of a visited array 
// tc : O(4^(m*n))
// sc : O(m*n) stack space 
class Solution
{
public:
    
    void f(int i ,int j,vector<vector<int>> &grid ,int n  ,vector<string> &ans,string ds ,vector<vector<int>> &vis)
    {
        // base case 
        if(i==n-1 and j==n-1)
        {
            ans.push_back(ds);
            return;
        }
        
        // Explore all the possible paths
        // Downward
        if(i+1<n and vis[i+1][j]==0 and grid[i+1][j]==1)
        {
            vis[i][j]=1;
            
            ds.push_back('D');
            f(i+1,j,grid,n,ans,ds,vis);
            ds.pop_back();
            
            vis[i][j]=0;
        }
        
        // Upward
        if(i-1>=0 and vis[i-1][j]==0 and grid[i-1][j]==1)
        {
            vis[i][j]=1;
            
            ds.push_back('U');
            f(i-1,j,grid,n,ans,ds,vis);
            ds.pop_back();
            
            vis[i][j]=0;
        }
        
        // Rightward
        if(j+1<n and vis[i][j+1]==0 and grid[i][j+1]==1)
        {
            vis[i][j]=1;
            
            ds.push_back('R');
            f(i,j+1,grid,n,ans,ds,vis);
            ds.pop_back();
            
            vis[i][j]=0;
        }
        
        // Leftward
        if(j-1>=0 and vis[i][j-1]==0 and grid[i][j-1]==1)
        {
            vis[i][j]=1;
            
            ds.push_back('L');
            f(i,j-1,grid,n,ans,ds,vis);
            ds.pop_back();
            
            vis[i][j]=0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        string ds = "";
        
        vector<vector<int>>vis(n,vector<int>(n,0));
        
        if(m[0][0]==1)
        {
            f(0,0,m,n,ans,ds,vis);
        }
    
        return ans;
    }
    
};


// optimised approach 
// instead of using 4 if statements using a for loop and a string ir ="DLRU"
// using dx and dy array 
class Solution
{
public:
    
    void f(int i ,int j,vector<vector<int>> &grid ,int n  ,vector<string> &ans,string ds ,vector<vector<int>> &vis,int dx[],int dy[])
    {
        // base case 
        if(i==n-1 and j==n-1)
        {
            ans.push_back(ds);
            return;
        }
        
        string x = "ULDR";
        for(int ind=0;ind<4;ind++)
        {
            int nx = i + dx[ind];
            int ny = j + dy[ind];
            
            if(nx>=0 and ny>=0 and nx<n and ny<n and grid[nx][ny]==1 and vis[nx][ny]==0)
            {
                vis[i][j]=1;
                
                f(nx,ny,grid,n,ans,ds + x[ind] ,vis,dx,dy);
                
                vis[i][j]=0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        string ds = "";
        
        vector<vector<int>>vis(n,vector<int>(n,0));
        
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};
        
        // int dx[4] = {1,0,0,-1};
        // int dy[4] = {0,-1,1,0};
        
        
        if(m[0][0]==1)
        {
            f(0,0,m,n,ans,ds,vis,dx,dy);
        }
    
        return ans;
    }
};
