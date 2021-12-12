class Solution {
public:
    // use of unordered map 
    // tc:O(N)
    // SC: O(1)
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int max1=INT_MIN;
        int a=nums.size()/2;
        for(auto x :mp)
        {
            if(x.second>a)
            {
                return x.first;
            }
        }
        return -1;
    }
};
