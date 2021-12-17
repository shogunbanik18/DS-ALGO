
// TC: O(N^2)
// largest area of reactangle in a histogram
#include<bits/stdc++.h>
using namespace std;

// TC: O(N^2)
// Brute Force 
int area1(int arr[],int n)
{
    int ans=0;
    int minh;
    for(int i=0;i<n;i++)
    {
        minh=INT_MAX;
        for(int j=i;j<n;j++)
        {
            minh=min(arr[j],minh);
            int len=j-i+1; 
            ans=max(ans,len*minh);
        }
    } 
    return ans;
}

int main()
{ 
    int arr[]={2,1,5,6,2,3};
    int n=6;
    cout<<area1(arr,n)<<endl;
    return 0;
}
