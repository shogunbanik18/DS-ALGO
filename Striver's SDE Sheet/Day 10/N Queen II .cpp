// Finding all ossible combinations and storing it in a vector  then finding the size of the vector 
class Solution 
{
private:
    
   void f(int i,int j, vector<string> &grid, vector<vector<string>>& ans, vector<int> &leftrow,vector<int> &upperdiagonal,vector<int> &lowerdiagonal,int n)
    {
        // since we are filling up col wise 
        if(j==n)
        {
            ans.push_back(grid);
            return ; 
        }
        
        for(int i=0;i<n;i++)
        {
            if(leftrow[i]==0 and upperdiagonal[n-1 + j-i]==0 and lowerdiagonal[i+j]==0)
            {
                grid[i][j] = 'Q';
                
                leftrow[i]=1;
                upperdiagonal[n-1 + j-i]=1;
                lowerdiagonal[i+j]=1;
                
                f(i,j+1,grid,ans,leftrow,upperdiagonal,lowerdiagonal,n);
                
                grid[i][j] = '.';
                
                leftrow[i]=0;
                lowerdiagonal[i+j]=0;
                upperdiagonal[n-1+j-i]=0;
            }
        }
       
    }
    

    vector<vector<string>> solveNQueens(int n,vector<vector<string>>& ans)
    {
        vector<string> grid(n);
        
        string s(n,'.');
        
        for(int i=0;i<n;i++)
        {
            grid[i]= s;
        }
        
        // checking for 3 conditions using hashing 
        vector<int>leftrow(n,0);
        vector<int>lowerdiagonal((2* n ) - 1,0);
        vector<int>upperdiagonal((2 * n) - 1,0);
        
        f(0,0,grid,ans,leftrow,upperdiagonal,lowerdiagonal,n);
        
        return ans;
    }

public:
    int totalNQueens(int n) 
    {
        vector<vector<string>> ans;
        solveNQueens(n,ans);
        int b = ans.size();
        return b;
    }
};
