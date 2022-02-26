// note can be done using recursion but never preferable due to high time complexity

// Binary Search Approach
class Solution 
{
    public:
    //Function to find minimum number of pages
    
    // using binary search 
    // tc : o(logn)
    // sc:o(1)
    bool ispossible(int *arr,int mid,int N,int B)
    {
        int count=0;
        int sum=0;
        for(int i=0;i<N;i++)
        {
            if(arr[i]>mid)
            {
                return false;
            }
            
            if(sum+arr[i]>mid)
            {
                count++;
                sum=arr[i];
            }
            else
            {
                sum+=arr[i];
            }
        }
        if(count<B)
        {
                return true;
        }
        return false;
    }
    
    int findPages(int A[], int N, int M) 
    {
        if(M>N)
        {
            return -1;
        }
        int mini=A[0];
        int sum=0;
        
        for(int i=0;i<N;i++)
        {
            mini=min(mini,A[i]);
            sum+=A[i];
        }
        
        int low= mini;
        int high= sum;
        int res=0;
        while(low<=high)
        {
            int mid= (low +high)/2;
            if(ispossible(A,mid,N,M))
            {
                res=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return res;
    }  
};
