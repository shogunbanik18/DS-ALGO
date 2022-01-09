class Solution {
public:
    // tc: N! *N
    // sc: O(N)+O(N)
    void recur(vector<int>&ds,vector<vector<int>>&ans,vector<int>&nums,vector<int>&freq)
    {
        int n=nums.size();
        if(ds.size()==n)
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i]=1;
                recur(ds,ans,nums,freq);
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
        recur(ds,ans,nums,freq);
        return ans;
    }
};
