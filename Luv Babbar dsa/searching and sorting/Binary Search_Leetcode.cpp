class Solution {
public:
    // Binary search works on sorted arrays only
    // tc:o(logn)
    int binarysearch(vector<int>&nums,int target)
    {
        int l=0;
        int h=nums.size()-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target)
    {
        return binarysearch(nums,target);
    }
};
