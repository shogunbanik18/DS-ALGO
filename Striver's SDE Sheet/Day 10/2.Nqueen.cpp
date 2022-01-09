// Leetcode 
class Solution {
public:
//     using extra space     
    bool issafe(int row,int col,vector<string>board,int n)
    {
        // upper diagonal check 
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
        
        col=dupcol;
        row=duprow;
        while( col>=0)
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            col--;
        }
        
        // lower diagonal 
        col=dupcol;
        row=duprow;
        while( row<n and col>=0)
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
        if (col == n) {
        ans.push_back(board);
        return;
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
        string s(n,'.');
        
        for(int i=0;i<n;i++)
        {
            board[i]=s;  
        }
        solve(0,board,ans,n);
        return ans;
    }
};

    
// Optimized Solution     
// using haspmap 
class Solution {
public:
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,vector<int>&leftrow,
               vector<int>&upperdiag,vector<int>&lowerdiag,int n)
    {
       if (col == n) {
        ans.push_back(board);
        return;
      }
        
        for(int row=0;row<n;row++)
        {
              if(leftrow[row]==0 and upperdiag[n-1+col-row]==0 and lowerdiag[col+row]==0)
              {
                  board[row][col]='Q';
                  leftrow[row]=1;
                  lowerdiag[row+col]=1;
                  upperdiag[n-1+col-row]=1;
                  solve(col+1,board,ans,leftrow,upperdiag,lowerdiag,n);
                  board[row][col]='.';
                  leftrow[row]=0;
                  lowerdiag[row+col]=0;
                  upperdiag[n-1+col-row]=0;
              }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++)
        {
            board[i]=s;  
        }
        
        vector<int>leftrow(n,0);
        vector<int>upperdiag(2*n-1,0);
        vector<int>lowerdiag(2*n-1,0);
        solve(0,board,ans,leftrow,upperdiag,lowerdiag,n);
        return ans;
    }
};

    
    
    
    
