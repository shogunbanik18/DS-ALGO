public:
    
    int binarysearch(int arr[], int n, int k)
    {
        int l=0;
        int r=n-1;
        int mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(arr[mid]==k)
            {
                return mid;
            }
            
            else if(arr[mid]<k)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return -1;
        // code here
    }
};
