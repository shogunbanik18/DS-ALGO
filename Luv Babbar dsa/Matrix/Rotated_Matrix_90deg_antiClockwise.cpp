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
    // reverse(matrix.begin(),matrix.end());
     for (int i = 0; i < n; i++)
    {
        int low = 0, high = n - 1;
        while (low < high)
        {
            swap(matrix[low][i], matrix[high][i]);
            low++;
            high--;
        }
    }
    // Your code goes here
}
