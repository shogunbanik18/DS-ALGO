    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    
    // using sorting +2 pointer approach 
    // tc: o(2*nlogn)+o(n)
    // sc:o(1)
class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr,arr+n);
        sort(dep,dep+n);
        
        int count=1;
        int platform=1;
        int i=1;
        int j=0;
        while(i<n and j<n)
        {
            if(dep[j]>=arr[i])
            {
                count++;
                i++;
            }
            else if(dep[j]<arr[i])
            {
                count--;
                j++;
            }
            
            if(count>platform)
            {
                platform=count;
            }
        }
        return platform;
    }
};
