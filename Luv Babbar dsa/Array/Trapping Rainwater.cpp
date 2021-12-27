class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n)
{
    int left[n], right[n];
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], arr[i]);
    }
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], arr[i]);
    }

    long long ans = 0;
    for (int i=0; i < n; i++)
    {
        ans = ans + min(left[i], right[i]) - arr[i];
    }
    return ans;
}
};



// gfg 

    long long trappingWater(int arr[], int n)
    {
    // array preprocessing concept in rainwater trapping problem 
        vector<int>left(n);
        vector<int>right(n);
        
        left[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            left[i]=max(left[i-1],arr[i]);
        }
        
        right[n-1]=arr[n-1];
        for(int j=n-2;j>=0;j--)
        {
            right[j]=max(right[j+1],arr[j]);
        }
        
        long long ans=0;
        for(int k=0;k<n;k++)
        {
            ans=ans+min(left[k],right[k])-arr[k];
        }
        return ans;
    }
