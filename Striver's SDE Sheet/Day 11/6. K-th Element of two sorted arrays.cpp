class Solution{
    public:
    // using the merge method of mergesort
    // tc :o(Nlogn)
    // sc:o(N )
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        vector<int>v(n+m);
        int i=0,j=0,t=0;
        while(i<n and j<m)
        {
            if(arr1[i]<=arr2[j])
            {
                v[t++]=arr1[i++];
            }
            else
            {
                v[t++]=arr2[j++];
            }
        }
        while(i<n)
        {
            v[t++]=arr1[i++];
        }
        while(j<m)
        {
            v[t++]=arr2[j++];
        }
        int ans =v[k-1];
        return ans;
    }
    
    // Optimised brute force 
    // using merge method and count 
    // tc:o(k)
    // sc:o(1)
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=0,j=0,ans=0;
        int count=0;
        while(i<n and j<m)
        {
            if(count==k)
            {
                break;
            }
            else if(arr1[i]<arr2[j])
            {
                ans=arr1[i];
                i++;
            }
            else
            {
                ans=arr2[j];
                j++;
            }
            count++;
        }
        if(count!=k)
        {
            if(i!=n-1)
            {
                ans=arr1[k-count];
            }
            else
            {
                ans=arr2[k-count];
            }
        }
        return ans;
    }
    
//     Using Binary Search 
//   tc:o( log(min(n,m))
//   sc: o(1)
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m)
        {
            return kthElement(arr2,arr1,m,n,k);
        }
        
        int low =max(0,k-m);
        int high =min(k,n);
        while(low<=high)
        {
            int cut1= (low+high)/2;
            int cut2 =k-cut1;
            
            int left1 = (cut1==0)?INT_MIN:arr1[cut1-1];
            int left2 = (cut2==0)?INT_MIN:arr2[cut2-1];
            
            int right1 =(cut1==n)?INT_MAX:arr1[cut1];
            int right2= (cut2==m)?INT_MAX:arr2[cut2];
            
            if(left1<=right2 and left2<=right1)
            {
                return max(left1,left2);
            }
            else if(left1>right2)
            {
                high=cut1-1;
            }
            else
            {
                low=cut1+1;
            }
        }
        return 1;
    }
};
