class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) 
    {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==key)
            {
                mp[nums[i+1]]++;
            }
        }
        
        int ans=0;
        int maxi =0;
        for(auto x:mp)
        {
            if(x.second>maxi)
            {
                maxi=x.second;
                ans=x.first;
            }
        }
        return ans;
    }
};
