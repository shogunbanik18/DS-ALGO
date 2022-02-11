#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int x[n],y[n],z[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i]>>z[i];
    }
    
    int sum1=0,sum2=0,sum3=0,totalsum=0;
    for(int i=0;i<n;i++)
    {
        sum1+=x[i];
        sum2+=y[i];
        sum3+=z[i];
        totalsum=sum1+sum2+sum3;
    }
    
    if(sum1==0 and sum2==0 and sum3==0 and totalsum==0)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
}
