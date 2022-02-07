class Solution{

  public:
	int minDifference(int arr[], int n) 
	{
	    int totalsum=0;
	    for(int i=0;i<n;i++)
	    {
	        totalsum+=arr[i];
	    }
	    
	    int k=totalsum;
	    vector<bool>prev(k+1,0),curr(k+1,0);
        prev[0]=curr[0]=true;
        prev[arr[0]]=true;
        for(int ind=1;ind<n;ind++)
        {
            for(int target=1;target<=k;target++)
            {
                 bool nottake=prev[target];
                bool take=false;
                if(target>=arr[ind])
                {
                    take=prev[target-arr[ind]];
                }
               curr[target]=(take|nottake);
            }
            prev=curr;
        }
         int mini=1e9;
            for(int s1=0;s1<=totalsum/2;s1++)
            {
                if(prev[s1]==true)
                {
                    mini=min(mini,abs((totalsum-s1)-s1));
                }
            }
        return mini;
	    // Your code goes here
	} 
};
