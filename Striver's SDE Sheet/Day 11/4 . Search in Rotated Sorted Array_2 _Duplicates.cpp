// Case of Skipping the Duplicates 
class Solution {
public:
    // linear search 
    // tc:o(n)
    // sc:o(1)
    bool search(vector<int>& nums, int target) 
    {
        bool ans=false;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                ans=true;
            }
        }
        return ans;
    }
    
    // using binary search 
    // tc: o(logn)
    // sc:o(1)
    
     bool search(vector<int>& arr, int target) 
     {
         bool ans=false;
         int low= 0;
         int high= arr.size()-1;
         while(low<=high)
         {
             int mid= low + (high-low)/2;
             if(arr[mid]==target)
             {
                 ans=true;
                 break;
             }
             
             // special condition 
             if(arr[low]==arr[mid] and arr[high]==arr[mid])
             {
                 low++;
                 high--;
             }
             
             else if(arr[low]<=arr[mid])
             {
                 if(arr[low]<=target and arr[mid]>=target)
                 {
                    high=mid-1; 
                 }
                 else
                 {
                     low=mid+1;
                 }
             }
             else
             {
                 if(arr[mid]<=target and arr[high]>=target)
                 {
                     low=mid+1;
                 }
                 else
                 {
                     high=mid-1;
                 }
             }
         }
         return ans;
     }
};
