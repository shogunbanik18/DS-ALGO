#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>arr ={-5,1,2,-2,3};
    vector<int>v;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            v.push_back(arr[i]);
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=0)
        {
            v.push_back(arr[i]);
        }
    }
    
    // for(auto x:v)
    // {
    //     cout<<x<<" ";
    // }
    vector<int>ans;
    for(int i=0;i<n-1;i++)
    {
        int diff = arr[i+1]-arr[i];
        if(diff>1)
        {
            int sum=0;
            for(int j= min(arr[i],arr[i+1])+1;j<max(arr[i],arr[i+1]);j++)
            {
                sum+=j;
            }
            ans.push_back(sum);
        }
        else
        {
            ans.push_back(0);
        }
    }
    
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
}
