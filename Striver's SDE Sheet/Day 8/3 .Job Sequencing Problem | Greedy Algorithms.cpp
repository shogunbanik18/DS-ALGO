/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

// tc: o(nlogn)+o(n)
// sc:o(n)

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job a,Job b)
    {
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comp);
        int maxi= arr[0].dead;
        for(int i=1;i<n;i++)
        {
            maxi=max(maxi,arr[i].dead);
        }
        
        int slot[maxi+1];
        
        for(int i=0;i<=maxi;i++)
        {
            slot[i]=-1;
        }
        
        int count=0,profit=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>0;j--)
            {
                if(slot[j]==-1)
                {
                    slot[j]=i;
                    count++;
                    profit+= arr[i].profit;
                    break;
                }
            }
        }
        vector<int>v;
        v.push_back(count);
        v.push_back(profit);
        return v;
    } 
};
