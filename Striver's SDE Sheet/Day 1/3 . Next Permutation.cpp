// // using stl
// // not allowed 
// class Solution
// {
// public:
//     void nextPermutation(vector<int>& nums) 
//     {
//         int n = nums.size();
//         next_permutation(nums.begin(),nums.end());
//     }
// };

// Brute Force 
// Finding all possible permutations using extra space
// class Solution
// {
// public:
    
//     void f(int ind, vector<int>&ds , vector<vector<int>> &ans, vector<int>&nums)
//     {
//         int n = nums.size();
        
//         if(ind==n)
//         {
//             ans.push_back(ds);
//             return;
//         }
        
//         for(int i = ind;i<n;i++)
//         {
//             ds.push_back(nums[ind]);
//             f(ind+1, ds, ans,nums);
//             ds.pop_back();
//         }
//     }
    
//     void nextPermutation(vector<int>& nums) 
//     {
//         vector<vector<int>> ans;
//         vector<int>ds;
        
//         f(0,ds,ans,nums);
        
//         // for(int i=0;i<ans.size();i++)
//         // {
//         //     for(int j=0;j<ans.size();j++)
//         //     {
//         //         cout<<ans[i][j]<<" ";
//         //     }
//         //     cout<<endl;
//         // }
        
        
//         return ;
//     }
// };

// Optimisation using back peak travel
// tc : o(n) + o(n) + o(n)
// sc : o(1)
class Solution
{
public:
     void nextPermutation(vector<int>& nums) 
     {
        int  n = nums.size();
         
        int ind1 ,ind2;
         
         // traversing from the back
         for(ind1 = n-2 ; ind1 >=0 ; ind1--)
         {
             if(nums[ind1] < nums[ind1 + 1] )
             {
                 break;
             }
         }
         
         // if(already in order )
         if(ind1<0)
         {
             reverse(nums.begin() , nums.end());
         }
         
         // traversing
         else
         {
             for(ind2 = n-1; ind2 >ind1 ; ind2--)
             {
                 if(nums[ind2] > nums[ind1])
                 {
                     break;
                 }
             }

             swap(nums[ind1] , nums[ind2]);
             reverse(nums.begin() + ind1 + 1 ,nums.end());
         }
         
     }
};
