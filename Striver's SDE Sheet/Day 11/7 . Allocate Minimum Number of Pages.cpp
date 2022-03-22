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


// gfg 
// using the concept of binary search on answer
// tc : o(NlogN)
// sc : o(1)
class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool check(int mid,int *A,int N,int M)
    {
        int count=1,sum1=0;
        for(int i=0;i<N;i++)
        {
            if(sum1+A[i] <= mid)
            {
                 sum1 += A[i];
            }
            
            else
            {
                count+=1;
                if(count>M or A[i]>mid)
                {
                    return false;
                }
                sum1 = A[i];
            }
        }
        
        return true;
    }
    
    
    int findPages(int A[], int N, int M) 
    {
        int mini = 1e9;
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum += A[i];
            mini = min(mini,A[i]);
        }
    
        int low = mini;
        int high = sum;
        int ans=0;
        
        while(low<=high)
        {
            int mid  = low + (high-low)/2;
            
            if(check(mid,A,N,M)==true)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        
        return low;
    }
};
