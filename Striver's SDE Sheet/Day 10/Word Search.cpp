// using backtracking + dfs 
class Solution {
public:
    // using dfs 
    bool check(int i,int j,int index,vector<vector<char>>& board,string word)
    {
        if(index == word.size())
        {
            return true;
        }
        
        // out of bound cases 
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]!=word[index])
        {
            return false;
        }
        
        board[i][j] = '#';
        bool s = (check(i+1,j,index+1,board,word) or check(i,j+1,index+1,board,word) or check(i-1,j,index+1,board,word) or check(i,j-1,index+1,board,word));
        board[i][j] = word[index];
        
        return s;
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        int m = board.size();
        int n = board[0].size();
        
        for(int i =0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == word[0] and check(i,j,0,board,word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
