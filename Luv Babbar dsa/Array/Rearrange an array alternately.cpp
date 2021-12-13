// tc : O(N)
    // SC: O(N)
    void rearrange(long long *arr, int n) 
    { 
        vector<long long>v;
        for(int i=0;i<n;i++)
        {
            v.push_back(arr[i]);
        }
        
        int l=0;
        int h=n-1;
        int i=0;
        while(l<=h)
        {
            arr[i++]=v[h--];
            arr[i++]=v[l++];
        }
    	// Your code here
    }
