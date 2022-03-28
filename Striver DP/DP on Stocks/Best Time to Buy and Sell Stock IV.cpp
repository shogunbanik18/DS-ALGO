// // using dp[n][2][k] approach 
// // using recursion 
// tc : o(2^n)
// sc :o(1)
// class Solution 
// {
// public:
    
//     int f(int ind, int buy , int cap , vector<int> &prices)
//     {
//         int n = prices.size();
//         if(cap==0)
//         {
//             return 0;
//         }
        
//         if(ind==n)
//         {
//             return 0;
//         }
        
//         int profit=0;
//         if(buy==1)
//         {
//             int take = -prices[ind] + f(ind+1,0,cap,prices);
//             int nottake = 0 + f(ind+1,1,cap,prices);
//             profit = max(take,nottake);
//         }
        
//         else
//         {
//             int take = prices[ind] + f(ind+1,1,cap-1 ,prices);
//             int nottake = 0 + f(ind+1,0,cap,prices);
//             profit = max(take,nottake);
//         }
        
//         return profit;
//     }
        
//     int maxProfit(int k, vector<int>& prices) 
//     {
//         int n = prices.size();
//         int buy=1;
//         int cap = k;
//         return f(0,buy,cap,prices);
//     }
// };


// // using dp[n][2][k] approach 
// // using recursion + memoisation dp 
// // tc : o(n*2*(k+1))
// // sc : o(n*2*(k+1)) + o(n+2+k)
// class Solution 
// {
// public:
    
//     int f(int ind, int buy , int cap , vector<int> &prices ,  vector<vector<vector<int>>>& dp)
//     {
//         int n = prices.size();
//         if(cap==0)
//         {
//             return 0;
//         }
        
//         if(ind==n)
//         {
//             return 0;
//         }
        
//         if(dp[ind][buy][cap] != -1)
//         {
//             return dp[ind][buy][cap] ;
//         }
        
//         int profit=0;
//         if(buy==1)
//         {
//             int take = -prices[ind] + f(ind+1,0,cap,prices,dp);
//             int nottake = 0 + f(ind+1,1,cap,prices,dp);
//             profit = max(take,nottake);
//         }
        
//         else
//         {
//             int take = prices[ind] + f(ind+1,1,cap-1 ,prices,dp);
//             int nottake = 0 + f(ind+1,0,cap,prices,dp);
//             profit = max(take,nottake);
//         }
        
//         return dp[ind][buy][cap] = profit;
//     }
        
//     int maxProfit(int k, vector<int>& prices) 
//     {
//         int n = prices.size();
//         int buy=1;
//         int cap = k;
        
//         vector<vector<vector<int>>> dp (n, vector<vector<int>> (2, vector<int> (k+1,-1)));
        
//         return f(0,buy,cap,prices,dp);
//     }
// };

// // using dp[n][2][k] approach 
// // using Tabulation dp (Bottom up) 
// // tc : o(n*2*(k+1))
// // sc : o(n*2*(k+1))
// class Solution 
// {
// public:
//     int maxProfit(int k, vector<int>& prices) 
//     {
//         int n = prices.size();
//         int buy=1;
//         int cap = k;
        
//         vector<vector<vector<int>>> dp (n+1, vector<vector<int>> (2, vector<int> (k+1,0)));
        
//         // base case
//         // cap==0 
//         for(int ind = 0;ind< n ; ind++)
//         {
//             for(int buy=0;buy<=1;buy++)
//             {
//                dp[ind][buy][0]=0; 
//             }
//         }
        
//         // ind==n 
//         for(int buy= 0; buy<2 ; buy++)
//         {
//             for(int cap=1; cap<=k;cap++)
//             {
//                dp[n][buy][cap]=0; 
//             }
//         }
        
//         for(int ind=n-1; ind>=0; ind--)
//         {
//             for(int buy=1 ; buy>=0 ; buy--)
//             {
//                 for(int cap = 1; cap<=k ; cap++)
//                 {
//                     int profit=0;
//                     if(buy==1)
//                     {
//                         int take = -prices[ind] + dp[ind+1][0][cap];
//                         int nottake = 0 + dp[ind+1][1][cap];
//                         profit = max(take,nottake);
//                     }

//                     else
//                     {
//                         int take = prices[ind] + dp[ind+1][1][cap-1];
//                         int nottake = 0 + dp[ind+1][0][cap];
//                         profit = max(take,nottake);
//                     }

//                     dp[ind][buy][cap] = profit;
//                 }
//             }
//         }
        
//         return dp[0][buy][cap];
//     }
// };



// using dp[n][2][k] approach 
// using Tabulation dp (Bottom up) 
// tc : o(n*2*(k+1))
// sc : o(2+cap)
// space optimisation 
class Solution 
{
public:
         
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        int buy=1;
        int cap = k;
        
        vector<vector<int>> ahead(2, vector<int> (k+1,0));
        vector<vector<int>> curr(2, vector<int> (k+1,0));
        
        // base case
        // cap==0 
        for(int ind = 0;ind< n ; ind++)
        {
            for(int buy=0;buy<=1;buy++)
            {
               curr[buy][0]=0; 
            }
        }
        
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int buy=1 ; buy>=0 ; buy--)
            {
                for(int cap = 1; cap<=k ; cap++)
                {
                    int profit=0;
                    if(buy==1)
                    {
                        int take = -prices[ind] + ahead[0][cap];
                        int nottake = 0 + ahead[1][cap];
                        profit = max(take,nottake);
                    }

                    else
                    {
                        int take = prices[ind] +  ahead[1][cap-1];
                        int nottake = 0 + ahead[0][cap];
                        profit = max(take,nottake);
                    }

                    curr[buy][cap] = profit;
                }
                ahead =curr;
            }
        }
        
        return ahead[buy][cap];
    }
};


// using another way dp[n][4]
// k = 2 so dp[n* (2K)] approach

// class Solution 
// {
// public:
    
//     int f(int ind, int trans ,int k, vector<int>& prices)
//     {
//         int n = prices.size();
//         if(ind==n)
//         {
//             return 0;
//         }
        
//         if(trans== 2*k )
//         {
//             return 0;
//         }
        
//         int profit;
//         // Buy 
//         if(trans%2==0)
//         {
//              int take = -prices[ind] + f(ind+1 ,trans+1,k,prices);
//              int nottake = 0 + f(ind+1 ,trans,k, prices);
//              profit = max(take,nottake);
//         }
        
//         // sell 
//         else if(trans %2 !=0)
//         {
//              int take = prices[ind] + f(ind+1 ,trans+1,k,prices);
//              int nottake = 0 + f(ind+1 ,trans,k, prices);
//              profit = max(take,nottake);
//         }
        
//         return profit;
//     }
    
//     int maxProfit(int k,vector<int>& prices) 
//     {
//         int n = prices.size();
//         int transaction_no = 0;
        
//         return f(0,transaction_no , k, prices); 
//     }
// };


// // memoisation of dp[n] * 4 based appraoch 
// class Solution 
// {
// public:
    
//     int f(int ind, int trans ,int k, vector<int>& prices , vector<vector<int>>& dp)
//     {
//         int n = prices.size();
//         if(ind==n)
//         {
//             return 0;
//         }
        
//         if(trans== 2*k )
//         {
//             return 0;
//         }
        
//         if(dp[ind][trans] !=-1)
//         {
//             return dp[ind][trans];
//         }
        
//         int profit;
//         // Buy 
//         if(trans%2==0)
//         {
//              int take = -prices[ind] + f(ind+1 ,trans+1,k,prices,dp);
//              int nottake = 0 + f(ind+1 ,trans,k, prices,dp);
//              profit = max(take,nottake);
//         }
        
//         // sell 
//         else if(trans %2 !=0)
//         {
//              int take = prices[ind] + f(ind+1 ,trans+1,k,prices,dp);
//              int nottake = 0 + f(ind+1 ,trans,k, prices,dp);
//              profit = max(take,nottake);
//         }
        
//         return profit;
//     }
    
//     int maxProfit(int k,vector<int>& prices) 
//     {
//         int n = prices.size();
//         int transaction_no = 0;
        
//         vector<vector<int>>dp(n , vector<int>(2*k ,-1));
        
//         return f(0,transaction_no , k, prices,dp); 
//     }
// };
