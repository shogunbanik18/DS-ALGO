// using the concept of binary Eponentiation 
// n = 5 , k = 3
// (n^k) = 125

// intuition  : k is either even or odd  
// so when k is even the it can c=be writtien as (n^2)^(k/2)
// when k is odd it can be written as n*(n)^(k-1)

#include<bits/stdc++.h>
using namespace std;

int find_pow(int n,int k)
{
    int nn = n;
    int kk = k;
    
    bool flag = false;
    if(k<0)
    {
        flag = true;
        k = k*-1;
    }
    
    double ans = 1;
    
    while(k!=0)
    {
        // even 
        if(k%2==0)
        {
            n = n *n;
            k = k/2;
        }
        
        // odd
        else
        {
            ans = ans * n;
            k = k-1;
        }
    }
    
    if(flag==false)
    {
        cout<<ans<<endl;
    }
    
    else
    {
        ans = 1/ans;
        cout<<ans<<endl;
    }
    
}

int main()
{
   int n,k;
   cin>>n>>k;
   
   find_pow(n,k);
}
