// similar to the problem of book allocation || using the concept of binary search on answer
// tc : o(n * logn)
// sc : o(1)
class Solution 
{
private:
    
    bool check(int mid ,int days, vector<int>&weights )
    {
        int count=1 ,sum1=0;
        
        for(int i=0 ; i<weights.size() ; i++)
        {
            // check for the sum then only add
            if(sum1 + weights[i] <= mid)
            {
                sum1 += weights[i];
            }
            
            else
            {
                count++;
                
                if(weights[i] >mid or count>days)
                {
                    return false;
                }
                
                sum1 = weights[i];
            }
        }
        return true;
    }
    
public:
    
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int n = weights.size();
        int mini = 1e9;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += weights[i];
            mini = min(mini,weights[i]);
        }
        
        // using binary search 
        int low = mini;
        int high = sum;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(check(mid,days,weights)==true)
            {
                high = mid-1;
            }
            
            else
            {
                low = mid+1;
            }
        }
        
        return low;
    }
};
