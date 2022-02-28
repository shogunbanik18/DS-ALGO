// Using Binary Search 
// tc:o(logn)*n
// sc:o(1)

bool canplace(vector<int>&arr , int n ,  int c,int mid)
{
    int count=1;
    int pos=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]-pos>=mid)
        {
            count++;
            pos=arr[i];
        }
        if(count==c)
        {
           return true;
        }
    }
    return false;
}

int chessTournament(vector<int> positions , int n ,  int c)
{
    sort(positions.begin(),positions.end());
    int low = 1;
    int high = positions[n-1]-positions[0];
	int ans;
    while(low<=high)
    {
        int mid =low + (high-low)/2;
        if(canplace(positions,n,c,mid))
        {
            ans=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}
