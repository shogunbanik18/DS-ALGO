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


// gfg  

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    // Brute force 
    // tc:o(n*n)
    // sc:o(1)
    // long long int inversionCount(long long arr[], long long N)
    // {
    //   long long int count=0;
    //   for(int i=0;i<N-1;i++)
    //   {
    //       for(int j=i+1;j<N;j++)
    //       {
    //           if(arr[i]>arr[j])
    //           {
    //               count++;
    //           }
    //       }
    //   }
    //   return count;
    //     // Your Code Here
    // }
    
    // tc:o(nlogn)
    // sc:o(n) creating an extra array
    // merging the array 
    long long merge(long long arr[],long long temp[],long long low,long long mid,long long high)
    {
        long long inv_count=0;
        long long i=low;
        long long j=mid;
        long long k=low;
        
        while((i<=mid-1) and (j<=high))
        {
            if(arr[i]<=arr[j])
            {
                temp[k++]=arr[i++];
            }
            else
            {
                temp[k++]=arr[j++];
                inv_count += (mid-i);
            }
        }
        
        while(i<=mid-1)
        {
            temp[k++]=arr[i++];
        }
        
        while(j<=high)
        {
            temp[k++]=arr[j++];
        }
        
        for(long long i=low;i<=high;i++)
        {
            arr[i]=temp[i];
        }
        return inv_count;
    }
    
    // merge sort step 
    long long mergesort(long long arr[],long long temp[],long long low ,long long  high)
    {
        long long mid,inv_count=0;
        if(low<high)
        {
            mid =(low+high)/2;
            inv_count+=mergesort(arr,temp,low,mid);
            inv_count+=mergesort(arr,temp,mid+1,high);
            inv_count+=merge(arr,temp,low,mid+1,high);
        }
        return inv_count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        mergesort(arr,temp,0,N-1);
    }
};

