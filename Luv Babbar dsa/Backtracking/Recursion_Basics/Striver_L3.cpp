#include<bits/stdc++.h>
using namespace std;

// print sum of 1st n numbers
// Iterative way 
void f(int n)
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=i;
    }
    cout << sum <<endl;
}

// Parameterized recursion 
void f1(int i,int sum)
{
    if(i<1)
    {
        cout<<sum<<endl;
        return;
    }
    f1(i-1,sum+i);
}

// recursive function way
int f2(int i)
{
    if(i==0)
    {
        return 0;
    }
    return i+f2(i-1);
}

// tc: O(N)
// sc :Auxialliary space call stack O(N)
// using recursive function 
int factorial(int n)
{
    if(n==0 or n==1)
    {
        return 1;
    }
    return n*factorial(n-1);
}

int main()
{
    int n;
    cin>>n;
    // f(n);
    // f1(n,0);
    // cout<<f2(n)<<endl;
    cout<<factorial(n)<<endl;
    return 0;
}
