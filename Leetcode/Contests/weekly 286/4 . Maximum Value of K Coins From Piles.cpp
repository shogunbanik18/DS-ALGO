// class Solution {
// public:
    
//     int f(int i,int j,int sum,int target,int count , vector<vector<int>>& arr)
//     {
//         if(count==target)
//         {
//             return count;
//         }
        
//         count = 1 + max(f(i+1,j,sum,target,count,arr),f(i,j+1,sum,target,count,arr));
//         int take = arr[i][j] + max(f(i+1,j,sum,target,count,arr),f(i,j+1,sum,target,count,arr));
        
//         int nottake = 0 + f(i+1,j,sum,target,count,arr);
//         count = max(f(i+1,j,sum,target,count,arr),f(i,j+1,sum,target,count,arr));
        
//         return max(take,nottake);
//     }
    
//     int maxValueOfCoins(vector<vector<int>>& piles, int k)
//     {
//        int n = piles.size();
//        int count =0,sum=0;
//        return f(0,0,sum,k,count,piles);   
//     }
// };

// using recursion + memeoisation 
// tc : o(n*k)
// sc :o(n*k) + o(n+k) stack space
class Solution {
public:
    
    int f(int ind,int k, vector<vector<int>>& piles ,vector<vector<int>>& dp)
    {
        int n = piles.size();
        if(ind==n or k==0)
        {
            return 0;
        }
        
        if(dp[ind][k]!= -1)
        {
            return dp[ind][k];
        }
    
        int best = 0 + f(ind+1,k,piles,dp);
        
        int sum=0;
        for(int i=0;i < min((int) piles[ind].size() ,k) ; i++)
        {
            sum += piles[ind][i];
            best = max(best, sum + f(ind+1, k - (i+1),piles ,dp) );
        }
        
        return dp[ind][k] = best;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k)
    {
       int n = piles.size();
       vector<vector<int>>dp (n,vector<int> (k+1,-1));
       return f(0,k,piles,dp);   
    }
};
