#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=4,d=2;
    int m=0;
    int maxpos=0;
    // cin>>n>>d;
    vector<int>v={7,8,9,3};
    for(int i=0;i<n;i++)
    {
        v[i]=(v[i]-1)/d;
    }
    
    for(int i=0;i<n;i++)
    {
        if(v[i]>=m)
        {
            m=v[i];
            maxpos=i;
        }
    }
    cout<<maxpos+1<<endl;
    return 0;
}

