// Leetcode sqrt(x)
class Solution {
public:
    // using stl 
    // int mySqrt(int x)
    // {
    //     int y= sqrt(x);
    //     return y;
    // }
    
    // using Binary Search 
    int mySqrt(int x) 
    {
       if(x==0)
       {
           return 0;
       }
       int low=1;
       int high=x;
       int ans;
       while(low<=high)
       {
           int mid =low+(high-low)/2;
           if(mid<=x/mid)
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
};


// Using General method 
double multiply(double number,int n)
{
    double ans=1;
    for(int i=1;i<=n;i++)
    {
        ans=ans*number;
    }
    return ans;
}

double findNthRootOfM(int n, int m) 
{
    double low=1;
    double high=m;
    double eps =1e-15;
    
    while((high-low)>eps)
    {
        double mid =(low+high)/2.0;
        if(multiply(mid,n)<m)
        {
            low=mid;
        }
        else
        {
            high=mid;
        }
    }
    double ans =low;
    return ans;
}


// using power function 
cout<<pow(m ,(double)1.0/(double)n);
