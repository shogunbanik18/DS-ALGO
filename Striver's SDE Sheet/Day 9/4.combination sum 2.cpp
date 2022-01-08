// tc :2^n *k 
// sc: k*x
class Solution {
public:
    void findcombination(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind;i<arr.size();i++)
        {
            if(i>ind and arr[i]==arr[i-1])
            {
                continue;
            }
            if(arr[i]>target)
            {
                break;
            }
            ds.push_back(arr[i]);
            findcombination(i+1,target-arr[i],arr,ans,ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        findcombination(0,target,candidates,ans,ds);
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

