class Solution{
    public:
    int Maximize(int a[],int n)
    {
        // using sorting 
        sort(a,a+n);
        long long  sum=0;
        long long int mod=(pow(10,9)+7); 
        for(long long int i=0;i<n;i++)
        {
            sum+=a[i]*i;
        }
        int x= (int)(sum %mod);
        return x;
        // Complete the function
    }
};
