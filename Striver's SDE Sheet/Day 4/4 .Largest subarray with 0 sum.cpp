class Solution{
    public:
    // using kadanes algo
    // using  loops 
    // tc:O(n^2)
    // solution wont work here check constraint
    int maxLen(vector<int>&A, int n)
    {
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=A[j];
                if(sum==0)
                {
                    maxi=max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
    
    // tc: o(Nlogn)
    // sc:O(N)
    // hashing concept  
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int>mp;
        int maxi=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=A[i];
            if(sum==0)
            {
                maxi=i+1;
            }
            else
            {
                if(mp.find(sum)!=mp.end())
                {
                    maxi=max(maxi,i-mp[sum]);
                }
                else
                {
                    mp[sum]=i;
                }
            }
        }
        return maxi;
    }
};
