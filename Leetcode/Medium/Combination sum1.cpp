class Solution {
public:
    // using Recursion n-1 to o approach 
//      void f(int ind,int target,vector<int>& arr,vector<int>&ds,vector<vector<int>>&ans)
//     {
//         if(target==0)
//         {
//             ans.push_back(ds);
//         }
//         if(ind==0)
//         {
//             if(target==arr[ind])
//             {
//                 ans.push_back(ds);
//             }
//             return;
//         }
        
//         if(arr[ind]<=target)
//         {
//             ds.push_back(arr[ind]);
//             f(ind,target-arr[ind],arr,ds,ans);
//             ds.pop_back();
//         }
//         f(ind-1,target,arr,ds,ans);
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target)
//     {
//         int n= candidates.size();
//         vector<vector<int>>ans;
//         vector<int>ds;
//         f(n-1,target,candidates,ds,ans);
//         return ans;
//     }
    
    
    // using Recursion 
    // tc: o(2^t *k)
    // sc:o(k*x)
    void f(int ind,int target,vector<int>& arr,vector<int>&ds,vector<vector<int>>&ans)
    {
        if(ind==arr.size())
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        
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
        int n= candidates.size();
        vector<vector<int>>ans;
        vector<int>ds;
        f(0,target,candidates,ds,ans);
        return ans;
    }
};
