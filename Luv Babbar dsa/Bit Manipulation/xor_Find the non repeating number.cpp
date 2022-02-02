#include<bits/stdc++.h>
using namespace std;

// xor 
// a^0=a 
// a^a=0
// commutative / associative property of xor  

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans^=arr[i];
    }
    cout<<ans<<endl;
}
