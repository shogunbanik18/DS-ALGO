class Solution {
public:
  
    // using merge method of mergesort 
    // tc : O(m+n)
    // sc: O(m+n)
    // Can be optimised using inplace mergeing 
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m=nums1.size();
        int n=nums2.size();
        vector<int>v(m+n);
        int i=0,j=0,k=0;
        while(i<m and j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                v[k]=nums1[i];
                i++;
                k++;
            }
            else
            {
                v[k++]=nums2[j++];
            }
        }
        
        while(i<m)
        {
            v[k++]=nums1[i++];
        }
        while(j<n)
        {
            v[k++]=nums2[j++];
        }
        
        double mid=0;
        int x =v.size();
        if(x%2!=0)
        {
            int a= x/2;
            mid = v[a];
        }
        else
        {
            int b =x/2;
            mid = ((float)v[b]+(float)v[b-1])/2.0;
        }
        return mid;
    }
    
    
    // using Binary Search 
    // tc: o(log(min(n1,n2)))
    // sc:o(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if(nums2.size()<nums1.size())
        {
            return findMedianSortedArrays(nums2,nums1);
        }
        int n1=nums1.size();
        int n2=nums2.size();
        int low=0;
        int high=n1;
        
        while(low<=high)
        {
            int cut1 =(low+high)/2;
            int cut2 = (n1+n2+1)/2 -cut1;
            
            int left1= cut1==0?INT_MIN : nums1[cut1-1];
            int left2= cut2==0?INT_MIN : nums2[cut2-1];
            
            int right1= cut1==n1?INT_MAX : nums1[cut1];
            int right2= cut2==n2?INT_MAX :nums2[cut2];
            
            if(left1<=right2 and left2<=right1)
            {
                if((n1+n2)%2==0)
                {
                    return (max(left1,left2)+min(right1,right2))/2.0;
                }
                else
                {
                    return max(left1,left2);
                }
            }
            else if(left1>right2)
            {
                high=cut1-1;
            }
            else
            {
                low=cut1+1;
            }
        }
        return 0.0;
    }
};
