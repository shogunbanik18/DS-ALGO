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

// optimised method gap method 
// using (N*LogN)
