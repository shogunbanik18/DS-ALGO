#include<bits/stdc++.h>
using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
//     vector<int>arr(n,0);
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
    
//     int mini=INT_MAX;
//     for(int i=0;i<n;i++)
//     {
//         mini=min(arr[i],mini);
//     }
//     cout<<mini<<" ";
// }

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    sort(arr.begin(),arr.end());
    cout<<arr[0]<<endl;
}
