// tc : O(n^2)
long long getInversions(long long *arr, int n)
{
    long long count=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j] and i<j)
            {
                count++;
            }
        }
    }
    return count;
    // Write your code here.
}


// using merge sort 
// tc:O(nlogn)
// sc:O(N)
#include<bits/stdc++.h>
using namespace std;

int merge(int arr[],int temp[],int left,int mid,int right)
{
    int i,j,k;
    int inv_count=0;
    
    i=left;
    j=mid;
    k=left;
    
    while(i<=mid-1 and j<=right)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
            inv_count=inv_count+(mid-i);
        }
    }
    
    while(i<=mid-1)
    {
        temp[k++]=arr[i++];
    }
    
    while(j<=right)
    {
        temp[k++]=arr[j++];
    }
    
    for(int i=left;i<=right;i++)
    {
        arr[i]=temp[i];
    }
    return inv_count;
}

int mergesort(int arr[],int temp[],int left,int right)
{
    int mid;
    int inv=0;
    if(right>left)
    {
        mid=(left+right)/2;
        inv+=mergesort(arr,temp,left,mid);
        inv+=mergesort(arr,temp,mid+1,right);
        inv+=merge(arr,temp,left,mid+1,right);
    }
    return inv;
}

int main()
{
    int arr[]={5,3,2,4,1};
    int n=5;
    int temp[n];
    int ans=mergesort(arr,temp,0,n-1);
    cout<<"No. of inversions are "<<ans<<endl;
    return 0;
}
