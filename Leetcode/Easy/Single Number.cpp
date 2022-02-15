class Solution {
public:
    // using Hashmap 
    // tc:o(n)
    // sc:o(n)
    int singleNumber(vector<int>& nums)
    {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto x:mp)
        {
            if(x.second==1)
            {
                return x.first;
            }
        }
        return 0;
    }
    
    // intuition of moores voting algo applicable for majority elements only 
    // using xor concept 
    // tc:o(n)
    // sc:o(1)
    int singleNumber(vector<int>& nums)
    {
       int res=0;
        for(int i=0;i<nums.size();i++)
        {
            res=res^nums[i];
        }
        return res;
    }
};
