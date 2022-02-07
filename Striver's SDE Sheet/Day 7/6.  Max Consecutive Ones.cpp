class Solution {
public:
    // tc:o(n)
    // sc:o(1)
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int n=nums.size();
        int count=0;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                count++; 
            }
            else
            {
                count=0;
            }
            maxi=max(count,maxi);
        }
        return maxi;
    }
};
