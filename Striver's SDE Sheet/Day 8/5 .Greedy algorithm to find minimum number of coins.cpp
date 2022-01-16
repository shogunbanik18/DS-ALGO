// Optimal Solution 
// tc:O(amount)
// // sc:O(1)
int findMinimumCoins(int amount) 
{
    int coins[]={1,2,5,10,20,50,100,500,1000};
    int mincoins=0;
    int n=9;
    
    for(int i=n-1;i>=0;i--)
    {
       if(amount-coins[i]>=0)
       {
           while(amount-coins[i]>=0)
           {   
           		amount=amount-coins[i];
//            		ans.push_back(coins[i]);
               mincoins++;
       		}
    	}
        if(amount==0)
        {
            break;
        }
    }
       return mincoins;
    // Write your code here
}

// // tc:O(amount)
// // sc:O(1)+O(N)
int findMinimumCoins(int amount) 
{
    int coins[]={1,2,5,10,20,50,100,500,1000};
    int n=9;
    vector<int>ans;
    
    for(int i=n-1;i>=0;i--)
    {
        while(amount>=coins[i])
           {   
           		amount=amount-coins[i];
           		ans.push_back(coins[i]);
       		}
    }
    return ans.size();
    // Write your code here
}

