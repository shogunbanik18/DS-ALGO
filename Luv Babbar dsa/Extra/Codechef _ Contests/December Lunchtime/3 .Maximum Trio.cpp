// Learning take care of the values types 
// long long  works here 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        sort(arr,arr+n);
        long long Ai=arr[n-1];
        long long Aj=arr[0];
        long long Ak=arr[n-2];
        long long ans=(Ai-Aj)*Ak;
        cout<<ans<<endl;
    }
}
