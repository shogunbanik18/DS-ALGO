#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p;
    cin>>p;
    if(p<0)
    {
        cout<<"INVALID INPUT"<<endl;
    }
    int p1 =p/4+p%4;
    if(p%2==0 and p>=0)
    {
        cout<<p1<<endl;
        cout<<p1<<endl;
        cout<<p1<<endl;
        cout<<p1<<endl;
    }
    
    else if(p%2!=0 and p>=0)
    {
        int a=p/4;
        cout<<a<<endl;
        cout<<a<<endl;
        cout<<a<<endl;
        cout<<p1<<endl;
    }
    return 0;
}
