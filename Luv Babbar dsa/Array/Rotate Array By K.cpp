class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    
    // tc: O(N)
    // SC: O(1)
    void reverse1(int arr[],int l,int r)
    {
        while(l<r)
        {
            int temp=arr[l];
            arr[l]=arr[r];
            arr[r]=temp;
            l++;
            r--;
        }
    }
    
    void rotateArr(int arr[], int d, int n)
    {
      reverse1(arr,0,d-1);
      reverse1(arr,d,n-1);
      reverse1(arr,0,n-1);
    }
    
    
    // TC: O(N)
    // SC: O(N)
    void rotateArr(int arr[], int d, int n)
    {
        vector<int>v;
        
        if(d==n)
        {
            return;
        }
        
        for(int i=d;i<n;i++)
        {
            v.push_back(arr[i]);
        }
        
        for(int i=0;i<d;i++)
        {
            v.push_back(arr[i]);
        }
        
        for(int k=0;k<v.size();k++)
        {
            arr[k]=v[k];
        }
    }   
};
