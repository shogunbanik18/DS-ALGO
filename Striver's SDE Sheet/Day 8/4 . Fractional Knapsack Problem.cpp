//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

// tc:o(nlogn)+o(n)
// sc:o(1)
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comp(Item a,Item b)
    {
        double r1 = (double)a.value/(double)a.weight;
        double r2 = (double)b.value/(double)b.weight;
        return r1>r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        int currweight=0;
        double finalans =0.0;
        for(int i=0;i<n;i++)
        {
            if(currweight+arr[i].weight<=W)
            {
                currweight+=arr[i].weight;
                finalans+=arr[i].value;
            }
            else
            {
               int remain =W-currweight;
               finalans+= (arr[i].value/(double)arr[i].weight)*(double)remain;
               break;
            }
        }
        return finalans;
    }
};
