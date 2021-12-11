class Solution {
public:
    void build(vector<int>&nums,vector<int>&v,int l,int r)
    {
        if(l<=r)
        {
            int mid=(l+r)/2;
            v.push_back(nums[mid]);
            build(nums,v,l,mid-1);
            build(nums,v,mid+1,r);
        }
    }

    vector<int> sortedArrayToBST(vector<int>& nums) 
    {
        vector<int>v;
        int l=0;
        int r=nums.size()-1;
        build(nums,v,l,r);
        return v;
        // Code here
    }
};
