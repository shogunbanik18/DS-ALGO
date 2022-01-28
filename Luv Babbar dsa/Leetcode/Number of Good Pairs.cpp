class Solution {
public:
    // Brute force 
    // tc:O(N^2)
    int numIdenticalPairs(vector<int>& nums) 
    {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]==nums[j])
                {
                    count++;
                }
            }
        }
        return count;
    }
    
    // using unordered map 
    // tc:o(n)
//     This is a basic concept of combinations:

// n_C_r = n! / r! * (n-r)!

// where:
// n_C_r	= 	number of combinations
// n	= 	total number of objects in the set
// r	= 	number of choosing objects from the set
    int numIdenticalPairs(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int ans=0;
        for(auto x:mp)
        {
            int n=x.second;
            ans+=(n*(n-1))/2;
        }
        return ans;
    }
};
