class Solution {
public:
//     tc: o(nlogn)
    int minimumCost(vector<int>& cost) 
    {
        int n=cost.size();
        sort(cost.begin(),cost.end());
        int i=n-1;
        int sum=0;
        while(i>=0)
        {
            if(i>=0)
            {
                sum+=cost[i];
                i--;
            }
            if(i>=0)
            {
                sum+=cost[i];
                i--;
                i--;
            }
        }
        return sum;
    }
};
