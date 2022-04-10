// class Solution {
// public:
//     int findLength(vector<int>& nums1, vector<int>& nums2) 
//     {
//         int n1 = nums1.size();
//         int n2 = nums2.size();
        
//         int i = 0,j = 0,count=0;
        
//         while(i<n1 and j<n2)
//         {
//             if(nums1[i]!=nums2[j])
//             {
//                 i++;
//             }
            
//             else if(nums1[i] == nums2[j])
//             {
//                 count++;
//                 i++;
//                 j++;
//             }
//         }
        
//         return count;
//     }
// };


// // finding the longest common substring 
// // tc : o(n*n)
// // sc : o(n*n)
// class Solution
// {
// public:
    
//     int findLength(vector<int>& nums1, vector<int>& nums2) 
//     {
//         int m = nums1.size();
//         int n = nums2.size();
        
//         vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
//         // Base cases 
//         for(int ind1 = 0;ind1<=m;ind1++)
//         {
//             dp[ind1][0] = 0;
//         }
        
//         for(int ind2 = 0;ind2<=n;ind2++)
//         {
//             dp[0][ind2] = 0;
//         }
        
//         // recursive cases 
//         int ans = 0;
//         for(int ind1 = 1;ind1<=m;ind1++)
//         {
//             for(int ind2 =1 ;ind2<=n ;ind2++)
//             {
//                 if(nums1[ind1-1] == nums2[ind2-1])
//                 {
//                     dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                    
//                 }
                
//                 else
//                 {
//                     dp[ind1][ind2] = 0;
//                 }
                
//                 ans = max(ans,dp[ind1][ind2]);
//             }
//         }
        
//         // // debug
//         // for(int i =0;i<m;i++)
//         // {
//         //     for(int j=0;j<n;j++)
//         //     {
//         //         cout<<dp[i][j]<<" ";
//         //     }
//         //     cout<<endl;
//         // }
        
//         cout<<endl;
//         return ans;
//     }
// };


// finding the longest common substring + space optimisation
// tc : o(n*n)
// sc : o(nn)
class Solution
{
public:
    
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int m = nums1.size();
        int n = nums2.size();
        
        vector<int>prev(n+1,0),curr(n+1,0);
        
        // recursive cases 
        int ans = 0;
        for(int ind1 = 1;ind1<=m;ind1++)
        {
            for(int ind2 =1 ;ind2<=n ;ind2++)
            {
                if(nums1[ind1-1] == nums2[ind2-1])
                {
                    curr[ind2] = 1 + prev[ind2-1];
                    
                }
                
                else
                {
                    curr[ind2] = 0;
                }
                
                ans = max(ans,curr[ind2]);
            }
            prev = curr;
        }
        
        // // debug
        // for(int i =0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        
        return ans;
    }
};
