// Leetcode 
class Solution {
public:
    // tc:Generally exponential (2^t) *k
    // sc: K* x
    
    void findcombination(int index,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>ds)
    {
        // base case 
        if(index==arr.size())
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        
        // recursive case 
        if(arr[index]<=target)
        {
            ds.push_back(arr[index]);
            findcombination(index,target-arr[index],arr,ans,ds);
            ds.pop_back();
        }
        findcombination(index+1,target,arr,ans,ds);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>ans;
        vector<int>ds;
        findcombination(0,target,candidates,ans,ds);
        return ans;
    }
};
