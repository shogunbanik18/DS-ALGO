#include<bits/stdc++.h>
using namespace std;

// Dynamic programming Approach 
int fibonacci(int N)
{
    int f[N];
    f[0]=0;
    f[1]=1;
    for(int i=2;i<N;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    for(int i=0;i<N;i++)
    {
        cout<<f[i]<<" ";
    }
}

// recursive approach 
// int fib(int N)
// {
//     if(N<=1)
//     {
//         return N;
//     }
//     return fib(N-1)+fib(N-2);
// }

int main()
{
    int N;
    cin>>N;
    fibonacci(N);
    cout<<endl;
    // for(int i=0;i<N;i++)
    // {
    //     cout<<fib(i)<<" ";
    // }
    return 0;
}
