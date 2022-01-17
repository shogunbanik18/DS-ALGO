class Solution{
    public:
    
    // tc ;O(NLOGN )
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a,a+n);
        int i=0;
        while(i<n)
        {
            if(k>0)
            {
                if(a[i]<0)
                {
                    a[i]=-1*a[i];
                    k--;
                }
            }
            i++;
        }
        
        sort(a,a+n);
        while(k>0)
        {
            a[0]=-a[0];
            k--;
        }
        
        long long sum=0;
        for(int x=0;x<n;x++)
        {
            sum+=a[x];
        }
        return sum;
        // Your code goes here
    }
    
    // using priority queue appraoch 
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // min heap 
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0;
        
        for(int i=0;i<n;i++)
        {
            pq.push(a[i]);
            sum+=a[i];
        }
        
        while(k--)
        {
            int x=pq.top();
            pq.pop();
            sum=sum-2*x;
            pq.push(-x);
        }
        return sum;
    }
};
