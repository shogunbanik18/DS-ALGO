// Recursion + set ds 
// tc: o(n! *n)
// sc :o(n!*n) + stack space + o(n) for set 
class Solution 
{
private: 
    void f(int ind,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds)
    {
        if(ind==arr.size())
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind;i<arr.size();i++)
        {
            ds.push_back(arr[i]);
            swap(arr[i],arr[ind]);
            
            f(ind+1,arr,ans,ds);
            
            swap(arr[i],arr[ind]);
            ds.pop_back();
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>>ans;
        vector<int>ds;
        f(0,nums,ans,ds);
        
        set<vector<int>>set;
        for(auto x : ans)
        {
            set.insert(x);
        }
        
        vector<vector<int>>v;
        for(auto x: set)
        {
            v.push_back(x);
        }
        
        return v;
    }
};
