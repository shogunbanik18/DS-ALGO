class Solution {
public:
    int maxDistToClosest(vector<int>& seats)
    {
        // 3 cases 
        // in between 
        // in extreme left 
        // in extreme right 
        
        int result=0;
        int val=0;
        
        int n=seats.size();
        // in between case 
        for(int i=0;i<n;i++)
        {
            if(seats[i]==1)
            {
                val=0;
            }
            else if(seats[i]==0)
            {
                val++;
                int mid=(val+1)/2;
                result=max(result,mid);
            }
        }
        
        // for start case 
        for(int i=0;i<n;i++)
        {
            if(seats[i]==1)
            {
                result=max(result,i);
                break;
            }
        }
        
        // for the end case 
        for(int i=n-1;i>=0;i--)
        {
            if(seats[i]==1)
            {
                result=max(result,n-1-i);
                break;
            }
        }
        return result;
    }
};
