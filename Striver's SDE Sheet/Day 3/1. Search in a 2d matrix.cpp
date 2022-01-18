class Solution {
public:
    // General Searching algortihm 
    // tc :O(N^2)
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        bool ans=false;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==target)
                {
                    ans=true;
                }
            }
        }
        return ans;
    }
  
  // using binary search and extra space
    // tc : log(n*m) +o(N*M)
    // sc:O(v)
    bool binarysearch(vector<int>&v,int l,int r,int target)
    {
        int mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(v[mid]==target)
            {
                return true;
            }
            else if(v[mid]>target)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        bool ans=false;
        vector<int>v;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                v.push_back(matrix[i][j]);
            }
        }
        
        for(int i=0;i<v.size();i++)
        {
            if(binarysearch(v,i,v.size()-1,target)==true)
            {
                return true;
            }
        }
        return false;
    }
    
    
  
  // Efficient solution 
    // binary search using constant space 
    // Time complexity: O(log(m*n)
    // Space complexity: O(1)
     bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {       
         if(!matrix.size())
         {
             return false;
         }
         int n=matrix.size();
         int m=matrix[0].size();
         
         int low=0;
         int high =(n*m)-1;
         while(low<=high)
         {
             int mid=(low + (high - low) / 2);
             if(matrix[mid/m][mid%m]==target)
             {
                 return true;
             }
             else if(matrix[mid/m][mid%m]<target)
             {
                 low=mid+1;
             }
             else
             {
                 high=mid-1;
             }
         }
         return false;
     }
  
  
  
//    // using binary search 
//     // tc :O(N^log(m))
//     bool searchMatrix(vector<vector<int>>& matrix, int target) 
//     {
//         int n=matrix.size();
//         int m=matrix[0].size();
//         int i=0;
//         int j=m-1;
//         while(i<n and j>=0)
//         {
//             if(matrix[i][j]==target)
//             {
//                 return true;
//             }
//             else if(matrix[i][j]>target)
//             {
//                 j--;
//             }
//             else
//             {
//                 i++;
//             }
//         }
//         return false;
//     }
  
};
