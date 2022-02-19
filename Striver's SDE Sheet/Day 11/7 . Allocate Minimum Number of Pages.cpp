// note can be done using recursion but never preferable due to high time complexity

// Binary Search Approach
class Solution 
{
    public:
    //Function to find minimum number of pages
    
    // using binary search .
    // tc : o(n)*log(n)
    // sc:o(1)
    bool ispossible(int *arr,int barrier,int n,int students)
    {
        int allocatedstud=1;
        int pages=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>barrier)
            {
                return false;
            }
            
            if(pages+arr[i]>barrier)
            {
                allocatedstud+=1;
                pages=arr[i];
               
            }
            else
            {
                pages+=arr[i];
            }
        }
        
        if(allocatedstud>students)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
    int findPages(int A[], int N, int M) 
    {
        if (M>N) return -1;
        
        int sum=0;
        int mini=A[0];
        
        for(int i=0;i<N;i++)
        {
            mini=min(mini,A[i]);
            sum+=A[i];
        }
        
        int low =mini;
        int high= sum;
        int res;
        while(low<=high)
        {
            int mid =(low+high)/2;
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
