// Brute force O(N^3 log m ) using set data structure
// sc :O(M) 

// Optimal solution 
// base case :Care of duplicate triplets
// tc : O(N^2)
// sc :O(M)  m no. of triplets 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
             if(i>0 && (nums[i]==nums[i-1]) )
             {
                 continue;
             }
            int l=i+1;
            int h=n-1;
            while(l<h)
            {
                int sum= nums[i]+nums[l]+nums[h];
                if(sum<0)
                {
                    l++;
                }
                else if(sum>0)
                {
                    h--;
                }
                else if(sum==0)
                {
                    // v.push_back(vector<int>{nums[i],nums[l],nums[h]});
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[h]);
                    v.push_back(temp);
                    
                    while(l<h and nums[l]==nums[l+1])
                    {
                        l++;
                    }
                    while(l<h && nums[h]==nums[h-1]) 
                    {
                        h--;
                    }
                    l++;
                    h--;
                }   
            }
        }
        return v;
    }
};
