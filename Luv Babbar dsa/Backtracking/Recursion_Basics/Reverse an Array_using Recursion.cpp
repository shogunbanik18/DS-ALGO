#include<bits/stdc++.h>
using namespace std;
// task : to reverse the array 

// using 2 pointer approach 
void reverse1(vector<int>&arr,int n)
{
    int l=0;
    int h=n-1;
    while(l<=h)
    {
        swap(arr[l],arr[h]);
        l++;
        h--;
    }
}

void reverse2(int l,int h,vector<int>&arr)
{
    if(l>=h)
    {
        return;
    }
    swap(arr[l],arr[h]);
    reverse2(l+1,h-1,arr);
}

void reverse3(int i,vector<int>&arr)
{
    int n=arr.size();
    if(i>=n/2)
    {
        return;
    }
    swap(arr[i],arr[n-1-i]);
    reverse3(i+1,arr);
}

int main()
{
    vector<int>arr{1,3,2,5,4};
    int n=arr.size();
    // using inbuilt stl
    // reverse(arr.begin(),arr.end());
    // reverse1(arr,n);
    // reverse2(0,n-1,arr);
    reverse3(0,arr);
    
    for(auto x: arr)
    {
        cout<<x<<" ";
    }
    return 0;
}
