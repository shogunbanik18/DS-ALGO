// Brute Force 
// tc : o(m*n)
// sc : o(1)
class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// using Binary Search
// tc : o(log(min(m,n)))
// sc : o(1)
class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int low =0;
        int high = (m*n) -1 ;
        
        while(low<=high)
        {
            int mid = (low + high)/2;
            
            if(matrix[mid/n][mid%n] == target)
            {
                return true;
            }
            
            else if(matrix[mid/n][mid%n] < target)
            {
                low = mid+1;
            }
            
            else
            {
                high = mid-1;
            }
        }
        return false;
    }
};
