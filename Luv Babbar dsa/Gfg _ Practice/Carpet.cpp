#include<bits/stdc++.h>
using namespace std;

int carpetox(int a,int b,int c,int d)
{
    int c1=0,c2=0;
    int ca=a,cb=b,cc=c,cd=d;
    while(a>c or b>d)
    {
        if(a>c)
        {
            a=a/2;
        }
        else
        {
            b=b/2;
        }
        c1++;
    }
    
    while(ca>cd or cb>cc)
    {
        if(ca>cd)
        {
            ca=ca/2;
        }
        else
        {
            cb=cb/2;
        }
        c2++;
    }
    return min(c1,c2);
}

int main()
{
    // int a=8,b=13;
    // int c=6,d=10;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<carpetox(a,b,c,d)<<endl;
    return 0;
}
