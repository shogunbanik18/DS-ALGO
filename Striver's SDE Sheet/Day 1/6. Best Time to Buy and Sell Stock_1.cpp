// tc: o(n^2)
// sc: o(1)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int ans=0;
        int n=prices.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                    ans = max(ans, prices[j] - prices[i]);
            }
        }
        return ans;
    }
};

// tc: o(n)
// sc: o(1)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int maxprofit=0;
        int minsofar = prices[0];
        int n=prices.size();
        for(int i=0;i<n-1;i++)
        {
            minsofar =min(prices[i],minsofar);
            int profit = max( profit,prices[i] - minsofar);
            maxprofit  = max (maxprofit,profit);
        }
        return maxprofit;
    }
};

// using dp based approach 
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int profit=0;
        int mini= prices[0];
        int n=prices.size();
        
        for(int i=1;i<n;i++)
        {
            int cost = prices[i]-mini;
            profit = max(profit,cost);
            mini = min (mini,prices[i]);
        }
        return profit;
    }
};
