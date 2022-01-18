#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k,n,w;
    cin>>k>>n>>w;
    
    int cost=0;
    for(int i=1;i<=w;i++)
    {
        cost+=i*k;
    }
    
    if(n>=cost)
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<cost-n<<endl;
    }
}


// int main()
// {
//     int a,b;
//     cin>>a>>b;
//     int year=0;
//     while(a<=b)
//     {
//         a=a*3;
//         b=b*2;
//         year++;
//         if(a>b)
//         {
//             break;
//         }
//     }
//     cout<<year<<endl;
// }
