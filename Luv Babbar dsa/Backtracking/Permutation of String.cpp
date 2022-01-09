// gfg
// tc: N! *N
// sc: O(1)
// only auxiliary space 
class Solution
{
	public:
	    void recur(string s,int index,int n,vector<string>&ans)
	    {
	        if(index==n)
	        {
	            ans.push_back(s);
	            return;
	        }
	        for(int i=index;i<n;i++)
	        {
	            swap(s[index],s[i]);
	            recur(s,index+1,n,ans);
	            swap(s[index],s[i]);
	        }
	    }
	
		vector<string>find_permutation(string S)
		{
		    vector<string>ans;
		    recur(S,0,S.size(),ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

// leetcode 
class Solution {
public:
    // tc: N! *N
    // sc: O(N)+O(N)
//     void recur(vector<int>&ds,vector<vector<int>>&ans,vector<int>&nums,vector<int>&freq)
//     {
//         int n=nums.size();
//         if(ds.size()==n)
//         {
//             ans.push_back(ds);
//             return;
//         }
        
//         for(int i=0;i<n;i++)
//         {
//             if(!freq[i])
//             {
//                 ds.push_back(nums[i]);
//                 freq[i]=1;
//                 recur(ds,ans,nums,freq);
//                 freq[i]=0;
//                 ds.pop_back();
//             }
//         }
//     }
    
//     vector<vector<int>> permute(vector<int>& nums)
//     {
//         vector<vector<int>>ans;
//         vector<int>ds;
//         int n=nums.size();
//         vector<int>freq(n,0);
//         recur(ds,ans,nums,freq);
//         return ans;
//     }
    
    // Optimized solution
    // tc :N! *N
    // sc: only ausiliary space 
    // call stack
     void recur(int index,vector<int>&nums,vector<vector<int>>&ans)
     {
         if(index==nums.size())
         {
             ans.push_back(nums);
             return;
         }
         for(int i=index;i<nums.size();i++)
         {
            swap(nums[index],nums[i]);
            recur(index+1,nums,ans);
            swap(nums[index],nums[i]);
         }
     }
     vector<vector<int>> permute(vector<int>& nums)
     {
         vector<vector<int>>ans;
         recur(0,nums,ans);
         return ans;
     }
};



