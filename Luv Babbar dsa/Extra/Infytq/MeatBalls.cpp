#include<bits/stdc++.h>
using namespace std;

// tc:o(n)
// sc:o(1)
int main()
{
    int n,d;
    cin>>n>>d;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
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
    cout<<maxpos+1<<endl;
    return 0; 
}
