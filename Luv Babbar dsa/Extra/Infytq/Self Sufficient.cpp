#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>earn(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>earn[i];
    }
    
    vector<int>cost(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>cost[i];
    }
    
    int mini=0;
    for(int i=0;i<n;i++)
    {
        if(cost[i]>earn[i])
        {
            mini+=(cost[i]-earn[i]);
        }
        else if(cost[i]<earn[i])
        {
            mini-=(earn[i]-cost[i]);
        }
    }
    cout<<mini<<endl;
}
