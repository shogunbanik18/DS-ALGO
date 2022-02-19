class Solution {
public:
    // tc:o(n)
    // sc:o(n)
    vector<int> runningSum(vector<int>& nums)
    {
        vector<int>v;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            v.push_back(sum);
        }
        return v;
    }
    
    // tc:o(n)
    // sc:o(1)
    vector<int> runningSum(vector<int>& nums)
    {
        for(int i=1;i<nums.size();i++)
        {
            nums[i]=nums[i]+nums[i-1];
        }
        return nums;
    }
};
