class Solution {
public:
    int f(int i,vector<int>&nums,vector<int>&dp)
    {
        if(i<0)
        {
            return 0;
        }
        
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int curr=nums[i];
        int sum=nums[i];
        int index=i-1;
        int nottake = 0 +f(i-1,nums,dp);
        
        while(index>=0 and nums[index]==curr)
        {
            sum+=nums[index];
            index--;
        }
        
        while(index>=0 and nums[index]==curr-1)
        {
            index--;
        }
        int take= sum+f(index,nums,dp);
        return dp[i]=max(take,nottake);
    }
    
    int deleteAndEarn(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,-1);
        return f(n-1,nums,dp);
    }
};
