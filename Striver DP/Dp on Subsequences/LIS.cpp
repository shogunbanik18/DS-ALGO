// // trying out al possible ways 
// // using recursion 
// // tc : o(2^n)
// // sc : o(n)
// class Solution
// {
// public:
    
//     int f(int ind ,int prevind ,vector<int>&nums, int n)
//     { 
//         if(ind==n)
//         {
//             return 0;
//         }
        
//         int nottake = 0 + f(ind+1,prevind,nums,n);
        
//         int take =  0;
//         if(prevind == -1 or nums[ind] > nums[prevind] ) 
//         {
//             take = 1 + f(ind+1, ind,nums,n);
//         }
        
//         return max(take,nottake);
        
//     }
    
//     int lengthOfLIS(vector<int>& nums) 
//     {
//         int n = nums.size();
//         return f(0,-1,nums,n);
//     }
// };

// // Optimisation  + shifting of coordinates
// // using Memoisation 
// // tc : o(n*n)
// // sc : o(n*n) + o(n+n)
// class Solution
// {
// public:
    
//     int f(int ind ,int prevind ,vector<int>&nums, int n,vector<vector<int>> &dp)
//     { 
//         if(ind==n)
//         {
//             return 0;
//         }
        
//         if(dp[ind][prevind+1]!=-1)
//         {
//             return dp[ind][prevind+1];
//         }
        
//         int nottake = 0 + f(ind+1,prevind,nums,n,dp);
        
//         int take =  0;
//         if(prevind == -1 or nums[ind] > nums[prevind] ) 
//         {
//             take = 1 + f(ind+1, ind,nums,n,dp);
//         }
        
//         return dp[ind][prevind+1] = max(take,nottake);
        
//     }
    
//     int lengthOfLIS(vector<int>& nums) 
//     {
//         int n = nums.size();
//         // shifting of coordinates 
//         vector<vector<int>> dp(n,vector<int>(n+1,-1));
//         return f(0,-1,nums,n,dp);
//     }
// };



// // Tabulation dp  + shifting of coordinates
// // using Bottom up  
// // tc : o(n*n)
// // sc : o(n*n)
// class Solution
// {
// public:
//     int lengthOfLIS(vector<int>& nums) 
//     {
//         int n = nums.size();
        
//         // shifting of coordinates 
//         vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
//         // base case
//         // dp[n][prevind] = 0
        
//         for(int ind = n-1;ind>=0 ;ind--)
//         {
//             for(int prevind = ind-1 ;prevind>=-1 ;prevind--)
//             {
//                 // copying the recurrence
//                 int nottake = 0 + dp[ind+1][prevind+1];
        
//                 int take =  0;
//                 if(prevind == -1 or nums[ind] > nums[prevind] ) 
//                 {
//                     take = 1 + dp[ind+1][ind+1];
//                 }

//                 dp[ind][prevind+1] = max(take,nottake);
//             }
//         }
            
//         return dp[0][-1+1];
//     }
// };



// // Tabulation dp  + shifting of coordinates
// // using Bottom up  space optimisation
// // tc : o(n*n)
// // sc : o(n+n)
// class Solution
// {
// public:
      
//     int lengthOfLIS(vector<int>& nums) 
//     {
//         int n = nums.size();
        
//         // shifting of coordinates 
//         vector<int> next(n+1,0) , curr(n+1,0);
        
//         // base case
//         // dp[n][prevind] = 0
        
//         for(int ind = n-1;ind>=0 ;ind--)
//         {
//             for(int prevind = ind-1 ;prevind>=-1 ;prevind--)
//             {
//                 // copying the recurrence
//                 int nottake = 0 + next[prevind+1];
        
//                 int take =  0;
//                 if(prevind == -1 or nums[ind] > nums[prevind] ) 
//                 {
//                     take = 1 + next[ind+1];
//                 }

//                 curr[prevind+1] = max(take,nottake);
//             }
//             next = curr;
//         }
            
//         return curr[-1+1];
//     }
// };


// // Required for tracing back the LIS
// // Another Tabulation approach
// // // Tabulation dp 
// // // using Bottom up  
// // // tc : o(n*n)
// // sc : o(n*n)
// class Solution
// {
// public:
//     int lengthOfLIS(vector<int>& nums) 
//     {
//         int n = nums.size();
        
//         // declaring all dp's with 1
//         vector<int> dp(n,1);
        
//         for(int ind=0; ind<=n-1; ind++)
//         {
//             for(int prevind = 0; prevind <=ind-1; prevind++)
//             {
//                 if(nums[ind] > nums[prevind])
//                 {
//                     dp[ind] = max(1+ dp[prevind] , dp[ind]);
//                 }
//             }
//         }
        
//         int maxi =1;
//         for(auto x : dp)
//         {
//             maxi = max(maxi,x);
//         }
//         return maxi;
//     }
// };

 // Required for tracing back the LIS
// Another Tabulation approach
// // Tabulation dp 
// // using Bottom up  
// // tc : o(n*n)
// sc : o(n*n)
// class Solution
// {
// public:
//     int lengthOfLIS(vector<int>& nums) 
//     {
//         int n = nums.size();
//         int maxi = 1;
//         int lastind = 0;
        
//         // declaring all dp's with 1
//         vector<int> dp(n,1),hash(n);
        
//         for(int ind=0; ind<=n-1; ind++)
//         {
//             hash[ind] = ind;
//             for(int prevind = 0; prevind <=ind-1; prevind++)
//             {
//                 if(nums[ind] > nums[prevind] and 1+ dp[prevind] > dp[ind])
//                 {
//                     dp[ind] = 1 + dp[prevind];
//                     hash[ind] = prevind;
//                 }
//             }
            
//              if(dp[ind] > maxi)
//             {
//                  maxi = dp[ind];
//                  lastind = ind;
//             }
//         }
       
//         vector<int> temp;
//         temp.push_back(nums[lastind]);
        
//         while(hash[lastind] != lastind)
//         {
//             lastind = hash[lastind];
//             temp.push_back(nums[lastind]);
//         }
        
//         reverse(temp.begin(),temp.end());
        
//         // debug 
//         for(auto x : temp)
//         {
//             cout<<x<<" ";
//         }
//         cout<<endl;
       
       
//         return maxi;
//     }
// };


// using Binary Search +lower bound function stl 
// lower bound return the first idx of occurence of an element
// tc : o(logn* n)
// sc : o(n)
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        
        vector<int>v;
        v.push_back(nums[0]);
        
        int len=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i] > v.back())
            {
                v.push_back(nums[i]);
                len++;
            }
            
            else 
            {
                int ind = lower_bound(v.begin(),v.end(),nums[i]) - v.begin();
                v[ind] = nums[i];
            }
        }
        
        // return v.size();
        return len;
    }
};
