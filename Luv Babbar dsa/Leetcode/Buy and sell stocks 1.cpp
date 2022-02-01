class Solution {
public:
    // // brute force 
    // // tc:o(n^2)
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        int maxprofit=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(prices[j]>prices[i])
                {
                    int profit =prices[j]-prices[i];
                    maxprofit=max(maxprofit,profit);
                }
            }
        }
        return maxprofit;
    }
    
     // Linear traversal
    // tc:o(n)
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        int mini=INT_MAX;
        int maxprofit=0;
        for(int i=0;i<n;i++)
        {
                mini=min(prices[i],mini);
                int profit=prices[i]-mini;
                maxprofit=max(maxprofit,profit);
        }
        return maxprofit;
    }
    
};
