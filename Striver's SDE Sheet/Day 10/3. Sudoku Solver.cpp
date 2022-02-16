class Solution {
public:
//   tc: O(9(n ^ 2)), in the worst case, for each cell in the n2 board, we have 9 possible numbers.

//   sc: O(1), since we are refilling the given board itself, there is no extra space required, so constant space complexity.
    
     bool solve(vector<vector<char>>& board)
     {
         for(int i=0;i<board.size();i++)
         {
             for(int j=0;j<board[0].size();j++)
             {
                 if(board[i][j]=='.')
                 {
                     for(char c='1';c<='9';c++)
                     {
                         if(isvalid(board,i,j,c))
                         {
                             board[i][j]=c;
                             if(solve(board)==true)
                             {
                                 return true;
                             }
                             else
                             {
                                    board[i][j]='.';
                             }
                         }
                     }
                    return false;
                 }  
             }
         }
         return true;
     }
    
    bool isvalid(vector<vector<char>>& board,int row,int col,int c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==c)
            {
                return false;
            }
            
            if(board[row][i]==c)
            {
                return false;
            }
            // using the concet of divide and modulo for matrix
            if(board[(row/3)*3 + i/3][(col/3)*3+i%3]==c)
            {
                return false;
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board)
    {
        solve(board);   
    }
};
