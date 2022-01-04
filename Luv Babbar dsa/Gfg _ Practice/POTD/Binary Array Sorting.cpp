class Solution{
  public:
    
    // A[]: input array
    // N: input array
    //Function to sort the binary array.
    // tc:O(N)
    // sc:O(N)
    
    void binSort(int A[], int N)
    {
        // using inbuilt sorting 
        // sort(A,A+N);
        
        // using 2 pointer aproach 
        int l=0;
        int h=N-1;
        while(l<h)
        {
            if(A[l]==1 and A[h]==0)
            {
                swap(A[l],A[h]);
                l++;
                h--;
            }
            else if(A[l]==0)
            {
                l++;
            }
            else if(A[h]==1)
            {
                h--;
            }
        }
    }
};
