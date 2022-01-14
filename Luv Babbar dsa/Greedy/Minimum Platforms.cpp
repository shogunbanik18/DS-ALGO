class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // using greedy approach 
        
        // sorting +two pointer approach 
        sort(arr,arr+n);
        sort(dep,dep+n);
        
        int platform=1;
        int result=1;
        int i=1,j=0;
        
        while(i<n and j<n)
        {
            if(arr[i]<=dep[j])
            {
                platform++;
                i++;
            }
            else if(arr[i]>dep[j])
            {
                platform--;
                j++;
            }
            if(platform>result)
            {
                result=platform;
            }
        }
        return result;
    	// Your code here
    }
};
