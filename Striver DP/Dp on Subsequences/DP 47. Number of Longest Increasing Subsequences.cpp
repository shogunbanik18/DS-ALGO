// using the concept of LIS
// tc : o(n*n)
// sc : o(1)
class Solution 
{
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        int maxi = 1;
        vector<int> dp(n,1),count(n,1);
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[i] > nums[j] and 1+dp[j] > dp[i])
                {
                    dp[i] = 1+ dp[j];
                    // inherit 
                    count[i] = count[j];
                }
                else if(nums[i]> nums[j] and 1+dp[j]==dp[i])
                {
                    // i will take you 
                    count[i] += count[j];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        
        int nos = 0;
        
//         // debug 
//         for(auto x : dp)
//         {
//             cout<<x<<" ";
//         }
//         cout<<endl;
        
//         for(auto x : count)
//         {
//             cout<<x<<" ";
//         }
//         cout<<endl;
        
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxi)
            {
                nos += count[i];
            }
        }
        return nos;
        
      
    }
};
