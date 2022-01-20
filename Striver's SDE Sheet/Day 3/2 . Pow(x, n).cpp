class Solution {
public:
    
    // most optimal solution
    // tc : o(logn)
    // sc:o(1)
    double myPow(double x, int n)
    {
        double ans=1.0;
        long long nn=n;
        if(nn<0)
        {
            nn=-1*nn;
        }
        while(nn)
        {
            if(nn%2==1)
            {
                ans=ans*x;
                nn=nn-1;
            }
            else
            {
                x=x*x;
                nn=nn/2;
            }
        }
        if(n<0)
        {
            ans=(double)(1.0)/(double)(ans);
        }
        return ans;
    }
    
//   check Brute force
    // check for integer range 
    // Brute force 
    // tc : o(n)
    // sc:o(1)
//   double mypow(double x,int n)
// {
//     double ans=1.0;
//     long long nn=n;
//     if(n<0)
//     {
//         nn=-1*nn;
//     }
//     for(int i=0;i<nn;i++)
//     {
//         ans=ans*x;
//     }
//     if(n<0)
//     {
//         ans=(double)1.0/(double)ans;
//     }
//     return ans;
// }
    
    // using stl library 
    // double myPow(double x, int n)
    // {
    //     double ans=pow(x,n);
    //     return ans;
    // }
};



// brute force 
// check for integer range 
#include<bits/stdc++.h>
using namespace std;

// brute force 
// tc:o(n)
// sc:o(1)
double mypow(double x,int n)
{
    double ans=1.0;
    long long nn=n;
    if(n<0)
    {
        nn=-1*nn;
    }
    for(int i=0;i<nn;i++)
    {
        ans=ans*x;
    }
    if(n<0)
    {
        ans=(double)1.0/(double)ans;
    }
    return ans;
}

int main()
{
    int x,n;
    cin>>x>>n;
    cout<<mypow(x,n)<<endl;
}
