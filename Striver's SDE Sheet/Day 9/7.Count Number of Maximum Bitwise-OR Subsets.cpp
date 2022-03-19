// similar to the concept of subsets 
// maxor will be the or of all the possible values 
// tc : recusrion(Exponential)
// sc :  stack space
class Solution {
public:
    int ans= 0;
    
    void f(int idx ,vector<int>&nums, int maxor,int val)
    {
        if(idx == nums.size() and val == maxor)
        {
            ans++;
            return;
        }
        
        if(idx>=nums.size())
        {
            return;
        }
        
        f(idx+1 ,nums,maxor , (val|nums[idx]));
        f(idx+1 ,nums,maxor, val);
    }
    
    int countMaxOrSubsets(vector<int>& nums)
    {
        int maxor = 0;
        
        for(auto x: nums)
        {
            maxor =  maxor | x;
        }
        
        f(0,nums,maxor,0);
        return ans;
    }
};
