#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,d;
    cin>>n>>d;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    // for(int i=0;i<n;i++)
    // {
    //     v[i]=(v[i]-1)/d;
    // }
    int maxi=0;
    int maxpos=0;

    for(int i=0;i<n;i++)
    {
        if(v[i]>maxi)
        {
            maxi=v[i];
            maxpos=i;
        }
    }
    cout<<maxi<<endl;
    cout<<maxpos+1<<endl;
    return 0; 
}

// check 
