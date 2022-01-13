class Solution{
    public:
    
    // X[], Y[]: input arrau
    // M, N: size of arrays X[] and Y[] respectively
    //Function to count number of pairs such that x^y is greater than y^x.
    // tc :O(N*N)
    // long long countPairs(int X[], int Y[], int M, int N)
    // {
    //     long long count=0;
    //     // tc : O(n^2)
    //     for(int i=0;i<M;i++)
    //     {
    //         for(int j=0;j<N;j++)
    //         {
    //             if(pow(X[i],Y[j])>pow(Y[j],X[i]))
    //             {
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    //   //Your code here
    // }
    
    int BS(int Y[],int k,int N)
    {
        int l=0;
        int h=N-1;
        int index=-1;
        int  mid;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(Y[mid]>k)
            {
                index=mid;
                h=mid-1;
            }
            else if(Y[mid]<=k)
            {
                l=mid+1;
            }
        }
        return index;
    }
    
    long long countPairs(int X[], int Y[], int M, int N)
    {
        sort(X,X+M);
        sort(Y,Y+N);
        
        int ones=0,twos=0,threes=0,fours=0;
        long long ans=0;
        for(int i=0;i<N;i++)
        {
            if(Y[i]==1)
            {
                ones++;
            }
            
            else if(Y[i]==2)
            {
                twos++;
                  
            }
            else if(Y[i]==3)
            {
                threes++;
            }
            else if(Y[i]==4)
            {
                fours++;
            }
        }
        
        for(int i=0;i<M;i++)
        {
            if(X[i]==2)
            {
                int index=BS(Y,2,N);
                if(index!=-1)
                {
                    ans=ans+N-index;
                }
                ans=ans+ones-threes-fours;
            }
            
            else if(X[i]>=3)
            {
                int index=BS(Y,X[i],N);
                if(index!=-1)
                {
                    ans=ans+N-index;
                }
                ans=ans+ones;
            }
            
            if(X[i]==3)
            {
                ans=ans+twos;
            }
        }
        return ans;
    }
};
