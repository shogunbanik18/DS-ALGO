// Leetcode 
class Solution {
public:
    // using optimised approach 
    // using reursion with skipping duplicates 
    // 2nd method of recursion 
    // tc:o(2^n)*k
    // sc:o(k*x)
    void f(int ind,int target, vector<int>&arr, vector<int>&ds, vector<vector<int>>&ans)
    {
        int n=arr.size();
        if(target==0)
        {
            ans.push_back(ds);
        }
        
        for(int i=ind;i<n;i++)
        {
            if(arr[i]>target)
            {
                break;
            }
            if(i>ind and arr[i]==arr[i-1])
            {
                continue;
            }
            ds.push_back(arr[i]);
            f(i+1,target-arr[i],arr,ds,ans);
            ds.pop_back();
        }
    }
    
     vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
     {
         sort(candidates.begin(),candidates.end());
         vector<vector<int>>ans;
         vector<int>ds;
         f(0,target,candidates,ds,ans);
         return ans;
     }
    
//     // Brute Force 
//     // using Recursion  + set 
    // tc: o(2^n) *klogn
    // sc: o(n)
    void f(int ind,int target,vector<int>&arr,vector<int>&ds,set<vector<int>>&k)
    {
        if(ind==arr.size())
        {
            if(target==0)
            {
                // sort(ds.begin(),ds.end());
                k.insert(ds);
                // ans.push_back(ds);
            }
            return;
        }
        if(arr[ind]<=target)
        {
            ds.push_back(arr[ind]);
            f(ind+1,target-arr[ind],arr,ds,k);
            ds.pop_back();
        }
        f(ind+1,target,arr,ds,k);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        set<vector<int>>k;
        vector<int>ds;
        f(0,target,candidates,ds,k);
        for(auto it=k.begin();it!=k.end();it++)
        {
            ans.push_back(*it);
        }
        return ans;
    }
};


// gfg 
// unique combination 
class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void findcombination(vector<vector<int>>&ans,vector<int>&arr,vector<int>&ds,int n,int index,int target)
    {
        // base case 
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        
        // recursive case
        for(int i=index;i<n;i++)
        {
            if(target>=arr[i])
            {
                ds.push_back(arr[i]);
                findcombination(ans,arr,ds,n,i,target-arr[i]);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {
        sort(A.begin(),A.end());
        vector<int>arr;
        int n=A.size();
        int comp=A[0];
        arr.push_back(A[0]);
        for(int i=1;i<n;i++)
        {
            if(A[i]!=comp)
            {
                arr.push_back(A[i]);
                comp=A[i];
            }
        }
    
        vector<vector<int>>ans;
        vector<int>ds;
        int m=arr.size();
        findcombination(ans,arr,ds,m,0,B);
        return ans;
        // Your code here
    }
};

