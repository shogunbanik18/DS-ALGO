class Solution{
public:

    // Brute force 
    // finding all the subset and the finding the maximum susbsets 
    // tc :O(n^2)

	// Function to find maximum product subarray
    // 	greedy 
	long long maxProduct(vector<int> arr, int n)
	{
	    long long ans=arr[0];
	    long long ma=ans;
	    long long mi=ans;
	    
	    for(int i=1;i<n;i++)
	    {
	        if(arr[i]<0)
	        {
	            swap(ma,mi);
	        }
	        ma=max( (long long)arr[i],ma*arr[i]);
	        mi=min( (long long)arr[i],mi*arr[i]);
	        ans=max(ans,ma);
	    }
	    return ans;
	    // code here
	}
};
