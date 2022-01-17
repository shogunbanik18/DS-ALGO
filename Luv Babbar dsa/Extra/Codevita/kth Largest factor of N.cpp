#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            v.push_back(i);
        }
    }
    int x=v[k];
    if(k>v.size())
    {
        x=1;
    }
    cout<<x<<" ";
    return 0;
}
