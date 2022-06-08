#include<bits/stdc++.h>
using namespace std;

// tc : o(n*m) 
// sc : o(1)
void merge1(vector<int>&arr1,vector<int>&arr2,int m,int n)
{
    int k;
    for(int i=0;i<m;i++)
    {
        if(arr1[i]>arr2[0])
        {
            swap(arr1[i],arr2[0]);
        }
        
        // using insertion sort algo
        int first = arr2[0];
        for(k=1;k<n and arr2[k]<first;k++)
        {
            arr2[k-1] = arr2[k];
        }
        arr2[k-1] = first;
    }
}

// tc : o(logn)
// sc : o(1)
void merge2(vector<int>&arr1,vector<int>&arr2,int m,int n)
{
    int gap = (m+n)/2;
    int i=0;
    int j=gap;
    
    while(gap!=0)
    {
        // 3 cases i and j is on arr1 
        if(i<m and j<m and arr1[i]>arr1[j])
        {
            swap(arr1[i],arr1[j]);
        }
        
        else if(i<m and j>=m and arr1[i]>arr2[j-m])
        {
            swap(arr1[i],arr2[j-m]);
        }
        
        else if(i>=m and j>=m and arr2[i-m]>arr2[j-m])
        {
            swap(arr2[i-m],arr2[j-m]);
        }
        
        if(gap==1)
        {
            gap = 0;
        }
        
        else
        {
            gap = gap/2;
        }
        
        i++;
        j++;
    }
        
}

void print(vector<int>&arr,int a)
{
    for(int i=0;i<a;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int>arr1{1,2,3,8,10};
    vector<int>arr2{4,7,9};
    
    int m = arr1.size();
    int n = arr2.size();
    merge1(arr1,arr2,m,n);
    print(arr1,m);
    print(arr2,n);
    
    merge2(arr1,arr2,m,n);
    print(arr1,m);
    print(arr2,n);
}

class Solution {
public:
        // Brute Force  
        // using extra space 
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        vector<int>v;
        for(int i=0;i<m;i++)
        {
            if(nums1[i]>0)
            {
                v.push_back(nums1[i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            v.push_back(nums2[i]);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            nums1[i]=v[i];
        }
        int k=0;
        for(int i=n+1;i<v.size();i++)
        {
            nums2[k]=v[i];
        }
    }
    
    
    // Using 2 pointer and reverse sorting 
    // Tarversing from back 
    // tc: O(K) 
    // sc :O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(i>=0 and j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[k]=nums1[i];
                k--;
                i--;
            }
            else
            {
                nums1[k]=nums2[j];
                j--;
                k--;
            }
        }
        while(j>=0)
        {
            nums1[k]=nums2[j];
            k--;
            j--;
        }
    }
    
    // using the 2 pointer  approach +swapping  (Not Applicatble for leetcode variant) 
    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    // {
        // int i,k;
        // for(int i=0;i<n;i++)
        // {
        //     if(nums1[i]>nums2[0])
        //     {
        //         int temp=nums1[i];
        //         nums1[i]=nums2[0];
        //         nums2[0]=temp;
        //     }
        //     //sorting the second array after every iteration
        //     int first=nums2[0];
        //     for(k=1;k<m && nums2[k]<first;k++)
        //     {
        //         nums2[k-1]=nums2[k];
        //     }
        //     nums2[k-1]=first;
        // }  
};


// gfg 
class Solution{
    public:
        //Function to merge the arrays.
        // using Brute force
        // tc:o(nlogn)+o(n)+o(n)
        // sc:o(n)
        void merge(long long arr1[], long long arr2[], int n, int m)
        {
            vector<int>v;
            for(int i=0;i<n;i++)
            {
                v.push_back(arr1[i]);
            }
            for(int i=0;i<m;i++)
            {
                v.push_back(arr2[i]);
            }
            sort(v.begin(),v.end());
            int k=0;
            for(int i=0;i<n;i++)
            {
                arr1[i]=v[k++];
            }
            for(int i=0;i<m;i++)
            {
                arr2[i]=v[k++];
            }
        }  
        
        // using 2 pointer + insertion sort 
        // tc:o(n*m)
        // sc:o(1)
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int i,k;
            for(i=0;i<n;i++)
            {
                if(arr1[i]>arr2[0])
                {
                    swap(arr1[i],arr2[0]);
                }
                
                int first=arr2[0];
                // using insertion sort algorithm 
                for(k=1;k<m and arr2[k]<first;k++)
                {
                    arr2[k-1]=arr2[k];
                }
                arr2[k-1]=first;
            }
            // code here 
        }
        
        // using the gap method 
        // tc:o(logn)
        // sc:o(1)
        void merge(long long arr1[], long long arr2[], int n, int m)
        {
            int gap =ceil((float)(n+m)/2);
            while(gap>0)
            {
                int i=0;
                int j=gap;
                while(j<(n+m))
                {
                    if(j<n and arr1[i]>arr1[j])
                    {
                        swap(arr1[i],arr1[j]);
                    }
                    else if(j>=n and i<n and  arr1[i]>arr2[j-n])
                    {
                        swap(arr1[i],arr2[j-n]);
                    }
                    else if(j>=n and i>=n and arr2[i-n]>arr2[j-n])
                    {
                        swap(arr2[i-n],arr2[j-n]);
                    }
                    i++;
                    j++;
                }
               if(gap==1)
               {
                   gap=0;
               }
               else
               {
                   gap=(ceil)((float)gap/2);
               }
            }
        }
};
