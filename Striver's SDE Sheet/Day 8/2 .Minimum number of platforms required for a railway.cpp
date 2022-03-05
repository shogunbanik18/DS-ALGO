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


// coding ninja 
// tc: o(nlogn) 
// sc:o(1)
int calculateMinPatforms(int at[], int dt[], int n) 
{
    sort(at,at+n);
    sort(dt,dt+n);
    int i=1;
    int j=0;
    int count=1,ans=1;
    while(i<n and j<n)
    {
        if(at[i]<=dt[j])
        {
            count++;
            i++;
        }
        else
        {
            count--;
            j++;
        }
        ans=max(ans,count);
    }
    return ans;
    // Write your code here.
}

// brute force
// tc: o(n*n)
// sc:o(1)
int calculateMinPatforms(int at[], int dt[], int n) 
{
    int ans=1;
    for(int i=0;i<n;i++)
    {
        int count=1;
        for(int j=i+1;j<n;i++)
        {
            if((at[i]>=at[j] and at[i]<=dt[j]) or (at[i]<=at[j] and at[j]<=dt[i]))
            {
                count++;
            }
        }
        ans=max(ans,count);
    }
    // Write your code here.
}
