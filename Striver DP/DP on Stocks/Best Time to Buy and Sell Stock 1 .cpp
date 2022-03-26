// tc : o(n*n)
// sc : o(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int miniprice = prices[0];
        int maxprofit = 0;
        
        for(int i=0;i<n;i++)
        {
            int miniprice = min(miniprice,prices[i]);
            for(int j=0;j<n;i++)
            {
                int profit = prices[j] - miniprice;
                maxprofit = max(maxprofit,profit);
            }
        }
        
        return maxprofit;
    }
};


// // tc : o(n)
// // sc : o(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int miniprice = prices[0];
        int maxprofit = 0;
        
        for(int i=0;i<n;i++)
        {
            miniprice = min(miniprice,prices[i]);
            int profit = prices[i] - miniprice;
            maxprofit = max(maxprofit,profit);
        }
        
        return maxprofit;
    }
};
