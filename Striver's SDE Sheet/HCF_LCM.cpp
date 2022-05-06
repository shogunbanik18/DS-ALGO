#include<bits/stdc++.h>
using namespace std;

// using iteration 
// tc : o(n)
// sc : o(1)
int gcd1(int a,int b)
{
    int ans = 0;
    for(int i = 1;i<=min(a,b);i++)
    {
        if(a%i==0 and b%i==0)
        {
            ans = i;
        }
    }
    return ans;
}

// using recursion 
// tc : o(log(min(a,b)))
// sc : o(1)
// int gcd(int a ,int b)
// {
//     if(b==0)
//     {
//         return a;
//     }
    
//     if(a>b)
//     {
//         swap(a,b);
//     }
    
//     return gcd(a,b%a);
// }

// lcm * hcf = a*b 

int lcm(int a,int b)
{
    int p = (a*b)/gcd1(a,b);
    return p;
}

int main()
{
    int a,b;
    cin>>a>>b;
    
    int hcf = gcd1(a,b);
    int lcm1 = lcm(a,b);
    cout<<hcf<<" "<<lcm1<<endl;
    return 0;
}
