#include<bits/stdc++.h>
using namespace std;

// tc: O(N)
// CALL STACK 
// sc :O(N)
// void f(int i,int n)
// {
//     // base case 
//     if(i>n)
//     {
//         return;
//     }
//     // cout<<"Shogun"<<endl;
//     cout<<i<<endl;
//     f(i+1,n);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     f(1,n);
// }

// void f(int i,int n)
// {
//     if(i==0)
//     {
//         return;
//     }
//     cout<<i<<endl;
//     f(i-1,n);
// }


// int main()
// {
//     int n;
//     cin>>n;
//     f(n,n);
// }

// print 1 to n using backtracking  
// using concept of backtracking
// void f(int i,int n)
// {
//     if(i==0)
//     {
//         return;
//     }
//     // backtracking step 
//     f(i-1,n);
//     cout<<i<<endl;
// }

// int main()
// {
//     int n;
//     cin>>n;
//     f(n,n);
// }

// print n to 1 using backtracking 
void f(int i,int n)
{
    if(i>n)
    {
        return;
    }
    f(i+1,n);
    cout<<i<<endl;
}

int main()
{
    int n;
    cin>>n;
    f(1,n);
    return 0;
}
