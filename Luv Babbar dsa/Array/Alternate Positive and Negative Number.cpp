class Solution{
public:

	void rearrange(int arr[], int n)
	{
	    vector<int>v;
	    vector<int>v1;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>=0)
	        {
	            v.push_back(arr[i]);
	        }
	        else if(arr[i]<=0)
	        {
	            v1.push_back(arr[i]);
	        }
	    }
	   
	    int i=0;
	    int l=0;
	    int r=0;
	    while(i<n)
	    {
	        if(l<v.size())
	        {
	            arr[i]=v[l];
	            i++;
	            l++;
	        }
	        if(r<v1.size())
	        {
	            arr[i]=v1[r];
	            i++;
	            r++;
	        }
	    }
	    // code here
	}
};
