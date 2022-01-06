class Solution {
public:
    // tc: O(M*N)
    // sc: O(M)+O(N)
    // using additional space vector/set 
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // set<int>row;
        // set<int>col;
        vector<int>row(n,1);
        vector<int>col(m,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    // row.insert(i);
                    // col.insert(j);
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // if(row.count(i) or col.count(j))
                if(row[i]==0 or col[j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
    

// optimal solution 
    // tc: 2*O(M*N)
    // sc: O(1) 
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int col0=1;
        for(int i=0;i<row;i++)
        {
            if(matrix[i][0]==0)
            {
                col0=0;
            }
            for(int j=1;j<col;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        // traversing from the back
        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=1;j--)
            {
                if(matrix[i][0]==0 or matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
            if(col0==0)
            {
                matrix[i][0]=0;
            }
        }
    }   
};