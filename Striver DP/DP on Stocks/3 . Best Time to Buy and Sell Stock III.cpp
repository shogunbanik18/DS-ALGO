// similar to stock 2 
// at most 2 transactions possible 

// // using Recursion 
// // tc : o(2^n) Exponential
// // sc : o(n) stack space
// class Solution 
// {
// public:
    
//     int f(int ind ,int buy_allowance ,int cap , vector<int>& prices)
//     {
//         // base case 
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
        
//         if(buy_allowance)
//         {
//             int take = -prices[ind] + f(ind+1 , 0,cap,prices);
//             int nottake = 0 + f(ind+1 ,1,cap, prices);
//             profit = max(take,nottake);
//         }
        
//         else
//         {
//             // 1 transaction done
//             int take = prices[ind] + f(ind+1 , 1 , cap-1 , prices);
//             int nottake = 0 + f(ind+1 ,0,cap ,prices);
//             profit = max(take,nottake);
//         }
        
//         return profit;
//     }
    
//     int maxProfit(vector<int>& prices) 
//     {
//         int n = prices.size();
//         int cap =2;
//         int buy_allowance = 1;
        
//         return f(0, buy_allowance ,cap ,prices);
//     }
// };

// // top down dp 
// // / using Recursion + Memoisation
// // tc : o(n8n) Exponential
// // sc : o(n*n) + o(n) stack space

// // Finding the Changing Parameter 
// class Solution 
// {
// public:
    
//     int f(int ind ,int buy_allowance ,int cap , vector<int>& prices , vector < vector < vector <int> > > & dp)
//     {
//         // base case 
//         int n = prices.size();
//         if(cap==0)
//         {
//             return 0;
//         }
        
//         if(ind==n)
//         {
//             return 0;
//         }
        
//         if(dp[ind][buy_allowance][cap]!=-1)
//         {
//             return dp[ind][buy_allowance][cap];
//         }
        
//         int profit=0;
        
//         if(buy_allowance)
//         {
//             int take = -prices[ind] + f(ind+1 , 0,cap,prices,dp);
//             int nottake = 0 + f(ind+1 ,1,cap, prices,dp);
//             profit = max(take,nottake);
//         }
        
//         else
//         {
//             // 1 transaction done
//             int take = prices[ind] + f(ind+1 , 1 , cap-1 , prices,dp);
//             int nottake = 0 + f(ind+1 ,0,cap ,prices,dp);
//             profit = max(take,nottake);
//         }
        
//         return dp[ind][buy_allowance] [cap] = profit;
//     }
    
//     int maxProfit(vector<int>& prices) 
//     {
//         int n = prices.size();
//         int cap =2;
//         int buy_allowance = 1;
        
//         vector < vector < vector <int> > > dp (n , vector<vector<int>> (2 , vector<int> (3,-1) ) );
        
//         return f(0, buy_allowance ,cap ,prices,dp);
//     }
// };


 // Bottom up dp 
// / using Tabulation
// tc : o(nn) Exponential
// sc : o(n*n) + o(n) stack space

// Finding the Changing Parameter 
// class Solution 
// {
// public:
    
//     int f(int ind ,int buy_allowance ,int cap , vector<int>& prices , vector < vector < vector <int> > > & dp)
//     {
//         // base case 
//         int n = prices.size();
//         if(cap==0)
//         {
//             return 0;
//         }
        
//         if(ind==n)
//         {
//             return 0;
//         }
        
//         if(dp[ind][buy_allowance][cap]!=-1)
//         {
//             return dp[ind][buy_allowance][cap];
//         }
        
//         int profit=0;
        
//         if(buy_allowance)
//         {
//             int take = -prices[ind] + f(ind+1 , 0,cap,prices,dp);
//             int nottake = 0 + f(ind+1 ,1,cap, prices,dp);
//             profit = max(take,nottake);
//         }
        
//         else
//         {
//             // 1 transaction done
//             int take = prices[ind] + f(ind+1 , 1 , cap-1 , prices,dp);
//             int nottake = 0 + f(ind+1 ,0,cap ,prices,dp);
//             profit = max(take,nottake);
//         }
        
//         return dp[ind][buy_allowance] [cap] = profit;
//     }
    
//     int maxProfit(vector<int>& prices) 
//     {
//         int n = prices.size();
//         int cap =2;
//         int buy_allowance = 1;
        
//         vector < vector < vector <int> > > dp (n , vector<vector<int>> (2 , vector<int> (3,-1) ) );
        
        
//         return f(0, buy_allowance ,cap ,prices,dp);
//     }
// };


// using Tabulation dp 
// Finding the Changing Parameter 
// class Solution 
// {
// public:
    
//     int maxProfit(vector<int>& prices) 
//     {
//         int n = prices.size();
//         int cap =2;
//         int buy_allowance = 1;
//         int profit;
        
//         vector < vector < vector <int> > > dp (n +1 , vector<vector<int>> (2 , vector<int> (3,0) ) );
        
//         // base case 
//         // changing paramenter 
        
//         // cap==0
//         for(int ind=0; ind<=n-1 ; ind++)
//         {
//             for(int buy_allowance = 0 ;buy_allowance <=1 ;buy_allowance ++)
//             {
//                 dp[ind][buy_allowance][0]=0;
//             }
//         }
        
//         // ind==n
//         for(int buy_allowance = 0 ;buy_allowance <=1 ;buy_allowance ++)
//         {
//             for(int cap = 1 ; cap <=2 ;cap ++)
//             {
//                 dp[n][buy_allowance][cap]=0;
//             }
//         }
        
        
//         for(int ind= n-1; ind >= 0 ; ind-- )
//         {
//             for(int buy_allowance =1;buy_allowance >=0 ;buy_allowance --)
//             {
//                 for(int cap = 1 ;cap <=2 ;cap ++)
//                 {
//                     if(buy_allowance)
//                     {
//                         int take = -prices[ind] + dp[ind+1] [0][cap];
//                         int nottake = 0 + dp[ind+1][1][cap];
//                         profit = max(take,nottake);
//                     }

//                     else
//                     {
//                         // 1 transaction done
//                         int take = prices[ind] + dp[ind+1][1][cap-1];
//                         int nottake = 0 + dp[ind+1] [0][cap];
//                         profit = max(take,nottake);
//                     }
        
//                  dp[ind][buy_allowance] [cap] = profit;
//                 }
//             }
//         }
        
//         return dp[0][buy_allowance][cap];
//     }
// };

// Space optimisation to 2d array 
// tc : o(n*n*n)
// sc : o(n+n)
// class Solution 
// {
// public:
    
//     int maxProfit(vector<int>& prices) 
//     {
//         int n = prices.size();
//         int cap =2;
//         int buy_allowance = 1;
//         int profit;
        
//         vector < vector <int> > ahead (2 , vector<int> (3,0) ) ,curr(2 , vector<int> (3,0));
        
//         // base case 
//         // changing paramenter 
        
//         for(int ind= n-1; ind >= 0 ; ind-- )
//         {
//             for(int buy_allowance =1;buy_allowance >=0 ;buy_allowance --)
//             {
//                 for(int cap = 1 ;cap <=2 ;cap ++)
//                 {
//                     if(buy_allowance)
//                     {
//                         int take = -prices[ind] + ahead[0][cap];
//                         int nottake = 0 + ahead[1][cap];
//                         profit = max(take,nottake);
//                     }

//                     else
//                     {
//                         // 1 transaction done
//                         int take = prices[ind] + ahead[1][cap-1];
//                         int nottake = 0 + ahead[0][cap];
//                         profit = max(take,nottake);
//                     }
        
//                     curr[buy_allowance] [cap] = profit;
//                 }
                
//                 ahead=curr;
//             }
//         }
        
//         return ahead[buy_allowance][cap];
//     }
// };




// using another way dp[n][4]
// class Solution 
// {
// public:
    
//     int f(int ind, int trans , vector<int>& prices)
//     {
//         int n = prices.size();
//         if(ind==n)
//         {
//             return 0;
//         }
        
//         if(trans==4)
//         {
//             return 0;
//         }
        
//         int profit;
//         // Buy 
//         if(trans%2==0)
//         {
//              int take = -prices[ind] + f(ind+1 ,trans+1,prices);
//              int nottake = 0 + f(ind+1 ,trans, prices);
//              profit = max(take,nottake);
//         }
        
//         // sell 
//         else if(trans %2 !=0)
//         {
//              int take = prices[ind] + f(ind+1 ,trans+1,prices);
//              int nottake = 0 + f(ind+1 ,trans, prices);
//              profit = max(take,nottake);
//         }
        
//         return profit;
//     }
    
//     int maxProfit(vector<int>& prices) 
//     {
//         int n = prices.size();
//         int transaction_no = 0;
        
//         return f(0,transaction_no , prices); 
//     }
// };

// Memoisation
// tc : o(n*n)
// sc : o(n*n) + o(n+n)
// class Solution 
// {
// public:
    
//     int f(int ind, int trans , vector<int>& prices, vector<vector<int>>& dp)
//     {
//         int n = prices.size();
//         if(ind==n)
//         {
//             return 0;
//         }
        
//         if(trans==4)
//         {
//             return 0;
//         }
        
//         if( dp[ind][trans]!=-1)
//         {
//             return  dp[ind][trans];
//         }
        
//         int profit;
//         // Buy 
//         if(trans%2==0)
//         {
//              int take = -prices[ind] + f(ind+1 ,trans+1,prices,dp);
//              int nottake = 0 + f(ind+1 ,trans, prices,dp);
//              profit = max(take,nottake);
//         }
        
//         // sell 
//         else if(trans %2 !=0)
//         {
//              int take = prices[ind] + f(ind+1 ,trans+1,prices,dp);
//              int nottake = 0 + f(ind+1 ,trans, prices,dp);
//              profit = max(take,nottake);
//         }
        
//         return dp[ind][trans] = profit;
//     }
    
//     int maxProfit(vector<int>& prices) 
//     {
//         int n = prices.size();
//         int transaction_no = 0;
        
//         vector<vector<int>>dp(n,vector<int>(4,-1));
//         return f(0,transaction_no , prices,dp); 
//     }
// };
