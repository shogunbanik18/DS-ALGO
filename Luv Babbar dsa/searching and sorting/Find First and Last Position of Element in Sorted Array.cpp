class Solution {
public:
    // tc : O(N)*2
    // sc: O(N) for the vector v
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int>v;
        int n=nums.size();
        int i=0,j=n-1;
        while(i<n)
        {
            if(nums[i]==target)
            {
                v.push_back(i);
                break;
            }
            i++;
        }
        while(j>=0)
        {
            if(nums[j]==target)
            {
                v.push_back(j);
                break;
            }
            j--;
        }
        if(v.size()==0)
        {
            v.push_back(-1);
            v.push_back(-1);
        }
        return v;
    }
    
    // using binary search 
    // tc :O(logn)
    int binarysearch(vector<int>&nums,int target,string x)
    {
        int mid;
        int result=-1;
        int l=0;
        int r=nums.size()-1;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(nums[mid]==target)
            {
                result=mid;
                (x=="first")?r=mid-1:l=mid+1;
                
            }
            else if(nums[mid]>target)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        // returning index of the element 
        return result;
    }
    
    vector<int> searchRange(vector<int>& nums, int target)
    {
        return {binarysearch(nums,target,"first"),binarysearch(nums,target,"second")};
    }
};
