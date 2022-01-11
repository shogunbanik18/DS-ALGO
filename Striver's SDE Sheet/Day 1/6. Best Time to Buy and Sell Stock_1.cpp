class Solution {
public:
    // Brute force 
    // tc:O(N^2)
    // SC: O(1)
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        int maxpro=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(prices[j]>prices[i])
                {
                    maxpro=max(maxpro,prices[j]-prices[i]);
                }
            }
        }
        return maxpro;
    }
    
    // tc : O(N)
    // sc:  O(1)
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        int maxprofit=0;
        int minsofar=prices[0];
        for(int i=0;i<n;i++)
        {
            minsofar=min(minsofar,prices[i]);
            int profit=prices[i]-minsofar;
            maxprofit= max(maxprofit,profit);
        }
        return maxprofit;
    } 
};

  // tc : O(N)
    // sc:  O(1)
//     int maxProfit(vector<int>& prices) 
//     {
//         int n=prices.size();
//         int mini=INT_MAX;
//         int maxi=0;
//         for(int i=0;i<n;i++)
//         {
//             mini=min(mini,prices[i]);
//             maxi=max(maxi,prices[i]-mini);
//         }
//         return maxi;
//     }
