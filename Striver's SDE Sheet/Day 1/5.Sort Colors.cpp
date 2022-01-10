class Solution {
public:
    // void sortColors(vector<int>& nums)
    // {
    //     sort(nums.begin(),nums.end());
    // }
    
    // using sliding window approach 
    void swap1(vector<int>&nums,int a,int b)
    {
        int temp=nums[a];
        nums[a]=nums[b];
        nums[b]=temp;
    }
    void sortColors(vector<int>& nums)
    {
        int n=nums.size();
        int i=0;
        int l=0;
        int r=n-1;
        while(i<=r)
        {
            if(nums[i]<1)
            {
                swap1(nums,i,l);
                i++;
                l++;
            }
            else if(nums[i]>1)
            {
                swap1(nums,i,r);
                r--;
            }
            else
            {
                i++;
            }
        }
    }
};
