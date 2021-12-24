#include<bits/stdc++.h>
using namespace std;

int main()
{
    // int T=4;
    // int E[5]={7,0,5,1,3};
    // int L[5]={1,2,1,3,4};
    // int E[4]={3,5,2,0};
    // int L[5]={0,2,4,4};
    
    int T;
    cin>>T;
    
    int E[T],L[T];
    
    for(int i=0;i<T;i++)
    {
        cin>>E[i];
    }
    
    for(int i=0;i<T;i++)
    {
        cin>>L[i];
    }
    
    
    int max1=INT_MIN;
    int sum=0;
    int guests=0;
    
    for(int i=0;i<5;i++)
    {
        guests=guests+E[i]-L[i];
        sum=max(sum,guests);
    }
    cout<<sum;
    return 0;
}
