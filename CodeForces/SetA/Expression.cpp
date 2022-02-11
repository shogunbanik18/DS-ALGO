#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a<1 or b<1 or c<1)
    {
        return 0;
    }
    
    int maxi=INT_MIN;
    
    int n1 = a+b*c;
    int n2 = a*(b+c);
    int n3 = a*b*c;
    int n4 = (a+b)*c;
    int n5 = a+b+c;
    int n6 = (a*b)+c;
    int arr[6]={n1,n2,n3,n4,n5,n6};
    sort(arr,arr+6);
    cout<<arr[5];
}
