class Solution {
public:
    // tc:O(N)
    // sc:O(N)
    vector<int> buildArray(vector<int>& nums) 
    {
        vector<int>ans(nums.size());
        for(int i=0;i<=nums.size()-1;i++)
        {
            ans[i]=nums[nums[i]];
        }
        return ans;
        
    }
    
    // tc:O(N)
    // sc:O(1)
    vector<int> buildArray(vector<int>&nums)
    {
        // store 2 no. in one location
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums[i]=nums[i]+n*(nums[nums[i]]%n);
        }
        for(int i=0;i<n;i++)
        {
            nums[i]=nums[i]/n;
        }
        return nums;
    }
};

