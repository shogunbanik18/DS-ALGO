// // try out all the possible ways 
// // using recursion 
// // tc : o(2^n)
// // sc : o(n) stack space

// class Solution
// {
// private:
    
//     int f(int ind,int canbuy, vector<int>& prices)
//     {
//         // base case
//         int n = prices.size();
        
//         if(ind==n)
//         {
//             return 0;
//         }
        
//         int profit=0;
        
//         // Buying the stocks
//         if(canbuy)
//         {
//             int take = -prices[ind] + f(ind+1,0,prices);
//             int nottake = 0 + f(ind+1,1,prices); 
            
//             profit = max(take,nottake);
//         }
        
//         // selling the stocks 
//         else
//         {
//             int take = prices[ind] + f(ind+1,1,prices);
//             int nottake = 0 + f(ind+1,0,prices);
            
//             profit = max(take,nottake);
//         }
        
//         return profit;
//     }
    
// public:
//     int maxProfit(vector<int>& prices) 
//     {
//         int n = prices.size();
//         int canbuy = 1; 
//         int ans = f(0,canbuy,prices);
//         return ans;
//     }
// };


// // try out all the possible ways 
// // using Memoisation using dp[n][buy] changing parameters
// // tc : o(n*n)
// // sc : o(n*n) + o(n+n) stack space

// class Solution
// {
// private:
    
//     int f(int ind,int canbuy, vector<int>& prices,vector<vector<int>>& dp)
//     {
//         // base case
//         int n = prices.size();
        
//         if(ind==n)
//         {
//             return 0;
//         }
        
//         int profit=0;
        
//         // Buying the stocks
//         if(dp[ind][canbuy]!=-1)
//         {
//             return dp[ind][canbuy];
//         }
        
//         if(canbuy)
//         {
//             int take = -prices[ind] + f(ind+1,0,prices,dp);
//             int nottake = 0 + f(ind+1,1,prices,dp); 
            
//             profit = max(take,nottake);
//         }
        
//         // selling the stocks 
//         else
//         {
//             int take = prices[ind] + f(ind+1,1,prices,dp);
//             int nottake = 0 + f(ind+1,0,prices,dp);
            
//             profit = max(take,nottake);
//         }
        
//         return dp[ind][canbuy] = profit;
//     }
    
// public:
//     int maxProfit(vector<int>& prices) 
//     {
//         int n = prices.size();
//         int canbuy = 1;
       
//         vector<vector<int>> dp(n,vector<int>(2,-1));
//         int ans = f(0,canbuy,prices,dp);
//         return ans;
//     }
// };


// // using Tabulation using dp[n+1][buy] changing parameters
// // Bottom up dp 
// // tc : o(n*n)
// // sc : o(n*n)

// class Solution
// {
// public:
//     int maxProfit(vector<int>& prices) 
//     {
//         int n = prices.size();
//         int canbuy = 1;
       
//         vector<vector<int>> dp(n+1,vector<int>(2,0));
        
//         // base case 
//         for(int canbuy = 0;canbuy<2; canbuy++)
//         {
//             dp[n][canbuy]=0;
//         }
        
        
//          int profit=0;
//         // writing the changing parameters 
//         for(int ind = n-1;ind>=0;ind--)
//         {
//             for(int canbuy=0; canbuy<2 ; canbuy++)
//             {
//                 if(canbuy==1)
//                 {
//                     int take = -prices[ind] + dp[ind+1][0];
//                     int nottake = 0 + dp[ind+1][1]; 

//                     profit = max(take,nottake);
//                 }

//                 // selling the stocks 
//                 else
//                 {
//                     int take = prices[ind] + dp[ind+1][1];
//                     int nottake = 0 + dp[ind+1][0];

//                     profit = max(take,nottake);
//                 }
                
//                 dp[ind][canbuy] = profit;
//             }
//         }
        
//          int ans = dp[0][canbuy];
//         return ans;
        
//     }
// };

// // using space optimisation
// // tc : o(n*n)
// // sc : o(n*n)
// class Solution
// {
// public:
//     int maxProfit(vector<int>& prices) 
//     {
//         int n = prices.size();
//         int canbuy = 1;
       
//         vector<int>ahead(2,0),curr(2,0);
        
//         // base case 
//         for(int canbuy = 0;canbuy<2; canbuy++)
//         {
//             ahead[canbuy]=0;
//         }
        
//         int profit=0;
//         // writing the changing parameters 
//         for(int ind = n-1;ind>=0;ind--)
//         {
//             for(int canbuy=0; canbuy<2 ; canbuy++)
//             {
//                 if(canbuy==1)
//                 {
//                     int take = -prices[ind] + ahead[0];
//                     int nottake = 0 + ahead[1]; 

//                     profit = max(take,nottake);
//                 }

//                 // selling the stocks 
//                 else
//                 {
//                     int take = prices[ind] + ahead[1];
//                     int nottake = 0 + ahead[0];

//                     profit = max(take,nottake);
//                 }
                
//                 curr[canbuy] = profit;
//             }
//             ahead = curr;
//         }
        
//         int ans = ahead[canbuy];
//         return ans;
        
//     }
// };


// using space optimisation using 4 variables 
// tc : o(n*n)
// sc : o(n)*4
class Solution
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        
        int aheadbuy=0, aheadnotbuy =0;
        int currbuy =0 ,currnotbuy=0;
        
        int profit=0;
        
        for(int ind = n-1;ind>=0;ind--)
        {
            currbuy = max(-prices[ind] + aheadnotbuy , 0 +aheadbuy);
                    
            currnotbuy = max(prices[ind] + aheadbuy , 0 + aheadnotbuy);
            
            aheadbuy = currbuy;
            aheadnotbuy = currnotbuy;
        }
        
        return aheadbuy;
    }
};
