// // buy and sell unlimited no. of times with cooldown 
// // using recurion 
// // tc: o(2^n)
// // sc : o(1)
// class Solution
// {
// public:
    
//     int f(int ind , int buy , vector<int> &prices)
//     {
//         int n = prices.size();
        
//         // base case 
//         if(ind>=n)
//         {
//             return 0;
//         }
        
//         int profit=0;
//         if(buy)
//         {
//             int take = -prices[ind] + f(ind +1,0,prices);
//             int nottake = 0 + f(ind+1,1,prices);
//             profit = max (take,nottake);
//         }
        
//         else
//         {
//             int take = prices[ind] + f(ind+2,1,prices);
//             int nottake = 0 + f(ind+1,0,prices);
//             profit = max(take,nottake);
//         }
        
//         return profit;
//     }
    
//     int maxProfit(vector<int>& prices)
//     {
//         int n = prices.size();
//         int buy=1;
        
//         return f(0,buy,prices); 
//     }
// };


// // buy and sell unlimited no. of times with cooldown 
// using Memoisation (Top down )
// tc: o(n*2)
// sc : o(n*2) + o(n+2)
// class Solution
// {
// public:
    
//     int f(int ind , int buy , vector<int> &prices , vector<vector<int>>& dp) 
//     {
//         int n = prices.size();
        
//         // base case 
//         if(ind>=n)
//         {
//             return 0;
//         }
        
//         if(dp[ind][buy]!=-1)
//         {
//             return dp[ind][buy];
//         }
        
//         int profit=0;
//         if(buy)
//         {
//             int take = -prices[ind] + f(ind +1,0,prices,dp);
//             int nottake = 0 + f(ind+1,1,prices,dp);
//             profit = max (take,nottake);
//         }
        
//         else
//         {
//             int take = prices[ind] + f(ind+2,1,prices,dp);
//             int nottake = 0 + f(ind+1,0,prices,dp);
//             profit = max(take,nottake);
//         }
        
//         return dp[ind][buy]= profit;
//     }
    
//     int maxProfit(vector<int>& prices)
//     {
//         int n = prices.size();
//         int buy=1;
        
//         vector<vector<int>> dp(n,vector<int>(2,-1));
//         return f(0,buy,prices,dp); 
//     }
// };


// // buy and sell unlimited no. of times with cooldown 
// // using Tabulation (Bottom Up )
// // tc: o(n*2)
// // sc : o(n*2)
// class Solution
// {
// public:    
//     int maxProfit(vector<int>& prices)
//     {
//         int n = prices.size();
//         int buy=1;
        
//         // at ind= n-1 it goes upto n+2
//         vector<vector<int>> dp(n+2,vector<int>(2,0));
        
//         // base case 
//         for(int buy = 0; buy <=1 ; buy++)
//         {
//             dp[n][buy] = 0;
//         }
        
//         // using bottom up appraoch 
//         for(int ind=n-1;ind>=0;ind--)
//         {
//             for(int buy = 0;buy<=1;buy++)
//             {
//                 int profit=0;
//                 if(buy)
//                 {
//                     int take = -prices[ind] + dp[ind +1][0];
//                     int nottake = 0 + dp[ind+1][1];
//                     profit = max (take,nottake);
//                 }

//                 else
//                 {
//                     int take = prices[ind] + dp[ind+2][1];
//                     int nottake = 0 + dp[ind+1][0];
//                     profit = max(take,nottake);
//                 }

//                 dp[ind][buy]= profit;
//             }
//         }
        
        
//         return dp[0][buy]; 
//     }
// };



// // buy and sell unlimited no. of times with cooldown 
// // using Tabulation (Bottom Up ) + space optimisation dp
// // tc: o(n*2)
// // sc : o(n+2)
// class Solution
// {
// public:    
//     int maxProfit(vector<int>& prices)
//     {
//         int n = prices.size();
//         int buy=1;
        
//         // at ind= n-1 it goes upto n+2
//         vector<vector<int>> dp(n+2,vector<int>(2,0));
        
//         // base case 
//         for(int buy = 0; buy <=1 ; buy++)
//         {
//             dp[n][buy] = 0;
//         }
        
//         // using bottom up appraoch  omitting the inside loop
//         for(int ind=n-1;ind>=0;ind--)
//         {
//             // buy condition 
//             dp[ind][1] = max (-prices[ind] + dp[ind +1][0], 0 + dp[ind+1][1]);
            
//             // notbuy condition 
//             dp[ind][0] = max (prices[ind] + dp[ind +2][1], 0 + dp[ind+1][0]);
//         }
        
//         return dp[0][buy]; 
//     }
// };

// / buy and sell unlimited no. of times with cooldown 
// 3 row Space optimisation 
// using Tabulation (Bottom Up ) + space optimisation dp (using 3 rows)
// tc: o(n)
// sc : o(6)
class Solution
{
public:    
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        int buy=1;
        
        // at ind= n-1 it goes upto n+2
        vector<int> ahead (2,0);
        vector<int> curr (2,0);
        vector<int> mostahead (2,0);
        
        // base case 
        // for(int buy = 0; buy <=1 ; buy++)
        // {
        //     ahead[buy] = 0;
        // }
        
        // using bottom up appraoch  omitting the inside loop
        for(int ind=n-1;ind>=0;ind--)
        {
            // buy condition 
            curr[1] = max (-prices[ind] + ahead[0], 0 + ahead[1]);
            
            // notbuy condition 
            curr[0] = max (prices[ind] + mostahead[1], 0 + ahead[0]);
            
            mostahead = ahead;
            ahead = curr;
        }
        
        return ahead[buy]; 
    }
};
