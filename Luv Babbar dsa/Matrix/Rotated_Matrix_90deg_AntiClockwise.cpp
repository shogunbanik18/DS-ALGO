//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
// tc: o(N^2)
// SC: O(1)

void swap1(vector<vector<int>>&matrix,int i,int j)
{
    int temp=matrix[i][j];
    matrix[i][j]=matrix[j][i];
    matrix[j][i]=temp;;
}
void rotate(vector<vector<int> >& matrix)
{
    int n=matrix.size();
    
    // transpose of matrix 
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            swap1(matrix,i,j);
        }
    }
    // reversing after transpose 
    reverse(matrix.begin(),matrix.end());
    // Your code goes here
}
