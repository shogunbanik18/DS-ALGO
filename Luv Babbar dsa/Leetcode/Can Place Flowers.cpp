class Solution {
public:
    // greedy algorithm 
    // using prev and next pointer
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        int total=0;
        for(int i=0;i<flowerbed.size() and total<n;i++)
        {
            if(flowerbed[i]==0)
            {
                int next=(i==flowerbed.size()-1)?0:flowerbed[i+1];
                int prev=(i==0)?0:flowerbed[i-1];
                if(next==0 and prev==0)
                {
                    flowerbed[i]=1;
                    total++;
                }
            }
        }
        return total==n;
    }
};
