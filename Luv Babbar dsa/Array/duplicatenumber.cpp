// use of hashing 
class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        unordered_map<int,int>m;
        int element;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        
        for(auto x:m)
        {
            if(x.second>1)
            {
                element=x.first;
            }
        }
        return element;
        
    }
};

// use of hashtable
// SC 0(1)
