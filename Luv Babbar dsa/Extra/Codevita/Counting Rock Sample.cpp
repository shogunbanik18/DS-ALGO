#include<bits/stdc++.h>
using namespace std;
// tc :O(s^r)
// sc:O(n)+O(n)

int main()
{
    int s,r;
    cin>>s>>r;
    vector<int>arr(s,0);
    for(int i=0;i<s;i++)
    {
        cin>>arr[i];
    }
    
    int l1,l2;
    int count=0;
    vector<int>v;
    int i=0;
    while(r--)
    {
        cin>>l1>>l2;
        for(int j=0;j<s;j++)
        {
            if(arr[j]>=l1 and arr[j]<=l2)
            {
                count++;
            }
        }
        v.push_back(count);
        count=0;
    }

    for(auto x:v)
    {
        cout<<x<<" ";
    }
    return 0; 
}
