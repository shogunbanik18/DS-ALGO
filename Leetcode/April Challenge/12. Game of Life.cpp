// Brute Force
// tc : o(m*n)
// sc : o(m*n) 
class Solution
{
public:
    
    int check(vector<vector<int>>&board,int i,int j,int m,int n)
    {
        int count = 0;
        
        // up
        if(i-1>=0)
        {
            if(board[i-1][j] == 1)
                count++;
        }
        
        // down
        if(i+1<m)
        {
            if(board[i+1][j] == 1)
                count++;
        }
        
        // left
        if(j-1>=0)
        {
            if(board[i][j-1] == 1)
                count++;
        }
        
        // right
        if(j+1<n)
        {
            if(board[i][j+1] == 1)
                count++;
        }
        
        // up left
        if(i-1>=0 and j-1>=0)
        {
            if(board[i-1][j-1] == 1)
                count++;
        }
        
        // up right
        if(i-1>=0 and j+1<n)
        {
            if(board[i-1][j+1] == 1)
                count++;
        }
        
        // down left
        if(i+1<m and j-1>=0)
        {
            if(board[i+1][j-1] == 1)
                count++;
        }
        
        // down right
        if(i+1<m and j+1<n)
        {
            if(board[i+1][j+1] == 1)
                count++;
        }
        
        cout<<count<<" ";
        return count;
    }
    
    void gameOfLife(vector<vector<int>>& board)
    {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> ans(m,vector<int>(n,0));        
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int  a = check(board,i,j,m,n); 
                
                if(board[i][j]==1 and a<2)
                {
                    ans[i][j] = 0;
                }
                
                else if(board[i][j]==1 and a==2 or a==3)
                {
                    ans[i][j] = 1;
                }
                
                else if(board[i][j]==1 and a>3)
                {
                    ans[i][j] = 0;
                }
                
                else if(board[i][j] ==0 and a ==3)
                {
                    ans[i][j] = 1;
                }
            }
        }
        
        // debug
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<ans[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        // board = ans;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                board[i][j] = ans[i][j];
            }
        }
    }
};
