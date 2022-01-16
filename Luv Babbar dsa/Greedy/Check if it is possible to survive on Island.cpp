class Solution{
public:
    // tc:O(1)
    // sc:O(1)
//   Greedy 
    int minimumDays(int S, int N, int M)
    {
        
        int sunday=S/7;
        int daytour=S-sunday;
        int sm=S*M;
        int days=sm/N;
        if(sm%N!=0)
        {
            days=days+1;
        }
        if(days<=daytour)
        {
            return days;
        }
        else
        {
            return -1;
        }
        // // code here
    }
};
