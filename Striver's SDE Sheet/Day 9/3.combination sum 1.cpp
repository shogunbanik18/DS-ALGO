class Solution {
public:
    // using Recursion
    // tc:o(2^t)*k  Generally Exponential 
    // sc:k*x
    void f(int ind,int target,vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans)
    {
        int n=arr.size();
        if(ind==n)
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        // Edge Case 
        if(arr[ind]<=target)
        {
            ds.push_back(arr[ind]);
            f(ind,target-arr[ind],arr,ds,ans);
            ds.pop_back();
        }
        f(ind+1,target,arr,ds,ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>ans;
        vector<int>ds;
        f(0,target,candidates,ds,ans);
        return ans;
    }
};
