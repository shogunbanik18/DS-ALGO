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



// Efficient Solution 
 // tc: O(Log(n+m))
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int low = 0, high = n1;
        
        while(low <= high)
        {
            int cut1 = (low + high) >> 1;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;
            
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            
            if(left1 <= right2 && left2 <= right1)
            {
                if((n1 + n2) % 2 == 0)
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                else
                    return max(left1, left2);
            }
            else if(left1 > right2)
                high = cut1 - 1;
            else
                low = cut1 + 1;
        }
        return 0.0;
    }
