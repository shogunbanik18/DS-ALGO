// Minimum Number of Removals to Make Mountain Array
// intuition 
// find the lis from the front  + lis from the back and find the longest bitonic sequence the substrack the max from n
// tc : o(n)
// sc : o(n)
class Solution 
{
public:
    int minimumMountainRemovals(vector<int>& nums) 
    {
        int n = nums.size();
        
        vector<long long int> dp1(n,1) ,dp2(n,1);
        
        // lis from the front 
        for(int i = 0;i<n;i++)
        {
            for(int j = 0 ;j<i;j++)
            {
                if(nums[i]> nums[j] and  1 +dp1[j] > dp1[i])
                {
                    dp1[i] = 1 + dp1[j];
                }
            }
        }
        
         // lis from the back 
        for(int i =n-1;i>=0;i--)
        {
            for(int j = n-1 ;j>i;j--)
            {
                if(nums[i]> nums[j] and  1 +dp2[j] > dp2[i])
                {
                    dp2[i] = 1 + dp2[j];
                }
            }
        }
        
        
        // debug 
//         for(auto x : dp1)
//         {
//             cout<<x<<" ";
//         }
//         cout<<endl;
        
//          for(auto x : dp2)
//         {
//             cout<<x<<" ";
//         }
//         cout<<endl;
        
        long long int ans = 3;
        for(int i = 0;i<n;i++)
        {
            
            if(dp1[i]==1 or dp2[i]==1)
                continue;
            
            
            long long int temp = dp1[i] + dp2[i] -1;
            ans = max(ans,temp);
        }
        
        // cout<<ans<<endl;
        long long int res = n- ans;
        return res;
    }
};
