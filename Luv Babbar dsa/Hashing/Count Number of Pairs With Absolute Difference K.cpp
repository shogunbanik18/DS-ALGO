class Solution {
public:
    // tc:o(n*n)
    // sc:o(1)
    int countKDifference(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(abs(nums[i]-nums[j])==k)
                {
                    count++;
                }
            }
        }
        return count;
    }
    
    // using unorderd_map
    // tc:o(nlogn)
    // sc:o(1)
    int countKDifference(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int count=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]+k])
            {
                count+=mp[nums[i]+k];
            }
            if(mp[nums[i]-k])
            {
                count+=mp[nums[i]-k];
            }
            mp[nums[i]]++;
        }
        return count;
    }
};
