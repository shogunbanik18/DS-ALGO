#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s;
    cin>>s;
    int flag=0;
    if(s=='a' or s=='e' or s=='i' or s=='o' or s=='u')
    {
        flag=1;
    }
    
    if(flag==1)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
