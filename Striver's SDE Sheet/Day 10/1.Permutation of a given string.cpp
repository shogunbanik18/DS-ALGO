class Solution {
public:
    // using Swapping +Recursion+ Backtracking 
    // tc:o(n!*n)
    // sc:o(n) only auxiliary stack space
    void f(int ind,vector<int>&nums,vector<vector<int>>&ans)
    {
        if(ind==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[ind],nums[i]);
            f(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>>ans;
        vector<int>ds;
        f(0,nums,ans);
        return ans;
    }
    
    
    // using the intital recursion + frequency map appraoch
    // tc: n!n
    // sc:o(n)+o(n) for frequency array+o(n) for auxilary space
    void f(vector<int>&ds,vector<int>&nums,vector<vector<int>>&ans,vector<int>&freq)
    {
        if(ds.size()==nums.size())
        {
            ans.push_back(ds);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i]=1;
                f(ds,nums,ans,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>>ans;
        vector<int>ds;
        int n=nums.size();
        vector<int>freq(n,0);
        f(ds,nums,ans,freq);
        return ans;
    }
};
