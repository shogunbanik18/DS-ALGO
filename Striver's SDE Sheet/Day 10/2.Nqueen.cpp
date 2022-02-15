class Solution {
public:   
//     brute force 
//     tc:o(n^3)
//     sc:o(n^2)
    bool issafe(int row,int col,vector<string>&board,int n)
    {
        int duprow=row;
        int dupcol=col;
        while(row>=0 and col>=0)
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            row--;
            col--;
        }
        
        row=duprow;
        col=dupcol;
        while(col>=0)
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            col--;
        }
        
        row=duprow;
        col=dupcol;
        while(row<n and col>=0)
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return ;
        }
        
        for(int row=0;row<n;row++)
        {
            if(issafe(row,col,board,n))
            {
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n, '.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans;
    }
    
    // using optimised approach 
    // hashing
    // tc: O( N^2 )
    // sc: O( N^2 )
    void solve(int col,vector<string>&board,vector<vector<string>>&ans, vector<int>&leftrow, vector<int>&upperdiagonal, vector<int>&lowerdiagonal,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return ;
        }
        
        for(int row=0;row<n;row++)
        {
            if(leftrow[row]==0 and lowerdiagonal[row+col]==0 and upperdiagonal[n-1+col-row]==0)
            {
                board[row][col]='Q';
                leftrow[row]=1;
                lowerdiagonal[row+col]=1;
                upperdiagonal[n-1+col-row]=1;
                solve(col+1,board,ans,leftrow,upperdiagonal,lowerdiagonal,n);
                board[row][col]='.';
                leftrow[row]=0;
                lowerdiagonal[row+col]=0;
                upperdiagonal[n-1+col-row]=0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n, '.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        vector<int>leftrow(n,0),upperdiagonal((2*n-1),0),lowerdiagonal((2*n-1),0);
        solve(0,board,ans,leftrow,upperdiagonal,lowerdiagonal,n);
        return ans;
    }
};
