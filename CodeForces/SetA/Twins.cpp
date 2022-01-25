#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int sum=0,count=0,minsum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    int mid=(sum)/2;
    sort(arr,arr+n);
    for(int i=n-1;i>=0;i--)
    {
        minsum+=arr[i];
        count++;
        if(minsum>mid)
        {
            break;
        }
    }
    cout<<count<<endl;
    return 0;
}
