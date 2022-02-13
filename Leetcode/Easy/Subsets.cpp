class Solution {
public:
    // using Recursion 
    // tc:o(2^n) +o(nlogn)
    // sc:o(n)
     void f(int ind,vector<int>&nums,vector<int>&ds,set<vector<int>>&res)
    {
        int n=nums.size();
        if(ind==n)
        {
            sort(ds.begin(),ds.end());
            res.insert(ds);
            return;
        }
        ds.push_back(nums[ind]);
        f(ind+1,nums,ds,res);
        ds.pop_back();
        f(ind+1,nums,ds,res);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        set<vector<int>>res;
        vector<int>ds;
        f(0,nums,ds,res);
        for(auto x =res.begin();x!=res.end();x++)
        {
            ans.push_back(*x);
        }
        return ans;
    }
    
    // tc: O(2^n)
    // sc: O(2^n * k)
    void f(int ind,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans)
    {
        ans.push_back(ds);
        for(int i=ind;i<nums.size();i++)
        {
            if(i!=ind and nums[i]==nums[i-1])
            {
                continue;
            }
            ds.push_back(nums[i]);
            f(i+1,nums,ds,ans);
            ds.pop_back();  
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        f(0,nums,ds,ans);
        return ans;
    }
};
