class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    
    // Brute Force O(N*N)
    // sc: O(N)
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int in[n]={0};
        int out[n]={0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(M[i][j]==1)
                {
                    in[j]++;
                    out[i]++;
                }
            }
            
        }
        
        for(int i=0;i<n;i++)
        {
            if(in[i]==n-1 and out[i]==0)
            {
                return i;
            }
        }
        return -1;
        // code here 
    }
    
    // tc :O(N)
    // SC:O(1)
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(M[c][i]==1)
            {
                c=i;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(i!=c and (M[c][i]==1 or M[i][c]==0))
            {
                return -1;
            }
        }
        return c;
    }
};
