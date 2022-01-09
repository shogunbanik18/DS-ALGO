class Solution 
{
    public:
    bool issafe(int grid[N][N],int x,int y,int choice)
    {
        for(int i=0;i<N;i++)
        {
            if(grid[i][y]==choice or grid[x][i]==choice)
            {
                return false;
            }
            
            if(grid[3*(x/3)+i/3][3*(y/3)+i%3]==choice)
            {
                return false;
            }
        }
        return true;
    }
    
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(grid[i][j]==0)
                {
                    for(int choice=1;choice<=9;choice++)
                    {
                        if(issafe(grid,i,j,choice)==true)
                        {
                            grid[i][j]=choice;
                            if(SolveSudoku(grid)==true)
                            {
                                return true;
                            }
                            grid[i][j]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
        // Your code here
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<grid[i][j]<<" ";
            }
        }
        // Your code here 
    }
};
