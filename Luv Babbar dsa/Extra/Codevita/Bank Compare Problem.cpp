#include<bits/stdc++.h>
using namespace std;

int main()
{
    double bank[5],p,s,mi,sum,emi,sq;
    int y,n,years,l=0;
    
    cin>>p;
    cin>>y;
    for(int k=0;k<2;k++)
    {
        cin>>n;
        sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>years;
            cin>>s;
            mi=0;
            sq=pow((1+s),years*12);
            emi = (p*(s))/(1-1/sq);
            sum=sum+emi;
        }
    }
    
    if(bank[0]<bank[1])
    {
        cout<<"A"<<endl;
    }
    else
    {
        cout<<"B"<<endl;
    }
    
}
