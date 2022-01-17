/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

bool isprime(int n)
{
    if((n==0) or (n==1))
    {
        return false;
    }
    for(int i=2;i<n;i++)
    {
        if((n%i==0))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    
    set<int>s;
    // s.insert(2);
    for(int i=2;i<=n;i++)
    {
        if((isprime(i))==true)
        {
            s.insert(i);
        }
    }
    
    // constraint 
    int sum=2;
    int count=0;
    for(auto x:s)
    {
        sum+=x;
        if(s.find(sum)!=s.end())
        {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
