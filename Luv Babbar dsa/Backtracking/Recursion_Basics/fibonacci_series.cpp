#include<bits/stdc++.h>
using namespace std;

// finding 1st n fibonacci series
// near about 
// tc : 2^N (Exponential)
int fib(int n)
{
    if(n==0 or n==1)
    {
        return n;
    }
    return fib(n-1)+fib(n-2);
}

int main()
{
    int n;
    cin>>n;
    // cout<<fib(n)<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<fib(i)<<" ";
    }
    return 0;
}
