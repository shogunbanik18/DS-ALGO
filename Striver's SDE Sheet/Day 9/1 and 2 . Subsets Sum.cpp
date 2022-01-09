// subset sum 1 
class Solution
{
public:
    // tc : 2^n before sorting
    // tc: 2^n log(2^n) after sorting
    // sc: O(N)
    void find(int index,int sum,vector<int>&arr,int N,vector<int>&v)
    {
        // base case 
        if(index==N)
        {
            v.push_back(sum);
            return;
        }
        // take 
        find(index+1,sum+arr[index],arr,N,v);
        // not take 
        find(index+1,sum,arr,N,v);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>v;
        find(0,0,arr,N,v);
        sort(v.begin(),v.end());
        return v;
        // Write Your Code here
    }
};

// subset sum 2 
// tc: 2^N *n
// sc:2^N *K
// auxiliary sace 2^n 
class Solution {
public:
    void find(int index,vector<int>&nums,vector<vector<int>>&ans,vector<int>&ds)
    {
        ans.push_back(ds);
        for(int i=index;i<nums.size();i++)
        {
            if(i!=index and nums[i]==nums[i-1])
            {
                continue;
            }
            ds.push_back(nums[i]);
            find(i+1,nums,ans,ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        find(0,nums,ans,ds);
        return ans;
    }
};
