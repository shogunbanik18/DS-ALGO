// intuition  : sort the array and just start thinking of LIS pattern 
// (Tabulation dp approach 2) with backtracking
// tc : o(n^2) + o(n)
// sc : o(n)
class Solution 
{
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int>hash(n);
        
        int lastind = 0;
        int maxi = 1;
        
        for(int ind = 0;ind<n;ind++)
        {
            hash[ind] = ind;
            for(int prevind = 0 ; prevind < ind ; prevind++)
            {
                if( (nums[ind] % nums[prevind] == 0) and dp[ind] < 1 + dp[prevind] )
                {
                    dp[ind] = 1 + dp[prevind];
                    hash[ind] = prevind;
                }
            }
            
            if(dp[ind]>maxi)
            {
                maxi = dp[ind];
                lastind = ind;
            }
        }
        
        vector<int>temp;
        temp.push_back(nums[lastind]);
        
        while(hash[lastind] != lastind)
        {
            lastind = hash[lastind];
            temp.push_back(nums[lastind]);
        }
        
        reverse(temp.begin(),temp.end());
        
        // Debug
//         for(auto x : dp)
//         {
//             cout<<x<<" ";
//         }
//         cout<<endl;
        
//         for(auto x : hash)
//         {
//             cout<<x<<" ";
//         }
//         cout<<endl;
        
//         for(auto x : temp)
//         {
//             cout<<x<<" ";
//         }
//         cout<<endl;
        
        return temp;
    }
};
