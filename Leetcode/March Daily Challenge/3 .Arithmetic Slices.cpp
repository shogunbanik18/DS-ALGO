class Solution {
public:
    // using brute force 
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int ans=0;
        int cnt=0;
        int n=nums.size();
        if(n<3)
        {
            ans=0;
            return ans;
        }
        
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]-nums[i-1]==nums[i+1]-nums[i])
            {
                ans++;
            }
            else
            {
                ans=0;
            }
            cnt+=ans;
        }
        return cnt;
    }
};
