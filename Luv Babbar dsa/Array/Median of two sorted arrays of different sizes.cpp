#include <bits/stdc++.h>
using namespace std;

int median(vector<int> arr1, vector<int> arr2)
{
    vector<int> v;
    for (int i = 0; i < arr1.size(); i++)
    {
        v.push_back(arr1[i]);
    }

    for (int j = 0; j < arr2.size(); j++)
    {
        v.push_back(arr2[j]);
    }

    sort(v.begin(), v.end());
    int k = v.size();
    if (k % 2 != 0)
    {
        int idx = (0 + (k - 1)) / 2;
        cout << v[idx] << endl;
    }
    else
    {
        int idx1 = (0 + (k - 1) / 2);
        int idx2 = idx1 + 1;
        int ans = (v[idx1] + v[idx2]) / 2;
        cout << ans << endl;
    }
}

int main()
{
    // vector<int> arr1 = {-5, 3, 6, 12, 15};
    // vector<int> arr2 = {-12, -10, -6, -3, 4, 10};
    vector<int> arr1 = {2, 3, 5, 8};
    vector<int> arr2 = {10, 12, 14, 16, 18, 20};
    median(arr1, arr2);
    return 0;
}


Leetcode
class Solution {
public:
    // tc: O(N)+o(M)+O((N+M)log(N+M))
//     i.e : O((N+M))log(N+M))
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
       vector<int>res;
        for(int i=0;i<nums1.size();i++)
        {
            res.push_back(nums1[i]);
        }
        
        for(int i=0;i<nums2.size();i++)
        {
            res.push_back(nums2[i]);
        }
        
        sort(res.begin(),res.end());
        int n=res.size();
        double mid;
        if(n%2==0)
        {
            int mid1=(0+(n-1))/2;
            int mid2=mid1+1;
            mid= (res[mid1]+res[mid2]);
            mid=mid/2;
        }
        else if(n%2!=0)
        {
            int mid1=(0+(n-1))/2;
            mid =res[mid1];
        }
        return mid;
    }
};
