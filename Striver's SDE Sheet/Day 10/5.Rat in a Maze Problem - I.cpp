class Solution{
    public:
    // tc :4^(N*M)
    // SC: auxiliary space  O(M*N)
    void solve(int i,int j,vector<vector<int>>&a,int n,vector<string>&ans,string move,vector<vector<int>>&vis)
    {
        if(i==n-1 and j==n-1)
        {
            ans.push_back(move);
            return;
        }
        
        // downward direction 
        if(i+1<n and !vis[i+1][j] and a[i+1][j]==1)
        {
            vis[i][j]=1;
            solve(i+1,j,a,n,ans,move+'D',vis);
            vis[i][j]=0;
        }
        
        // left direction 
        if(j-1>=0 and !vis[i][j-1] and a[i][j-1]==1)
        {
            vis[i][j]=1;
            solve(i,j-1,a,n,ans,move+'L',vis);
            vis[i][j]=0;
        }
        
        // Rightward direction 
        if(j+1<n and !vis[i][j+1] and a[i][j+1]==1)
        {
            vis[i][j]=1;
            solve(i,j+1,a,n,ans,move+'R',vis);
            vis[i][j]=0;
        }
        
        // Upward direction 
        if(i-1>=0 and !vis[i-1][j] and a[i-1][j]==1)
        {
            vis[i][j]=1;
            solve(i-1,j,a,n,ans,move+'U',vis);
            vis[i][j]=0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        vector<string>ans;
        // declaring visted array
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(m[0][0]==1)
        {
            solve(0,0,m,n,ans,"",vis);
        }
        return ans;
        // Your code goes here
    }
    
    
// optimized 

    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, 
    vector<vector<int>> &vis, int di[], int dj[]) 
    {
        if(i==n-1 && j==n-1) {
            ans.push_back(move);
            return; 
        }
        string dir = "DLRU"; 
        for(int ind = 0; ind<4;ind++)
        {
            int nexti = i + di[ind]; 
            int nextj = j + dj[ind]; 
            if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
                vis[i][j] = 1; 
                solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
                vis[i][j] = 0; 
            }
        }
    }
    // public:
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n, 0)); 
        int di[] = {+1, 0, 0, -1}; 
        int dj[] = {0, -1, 1, 0}; 
        if(m[0][0] == 1) solve(0,0,m,n, ans, "", vis, di, dj); 
        return ans; 
    }
};
