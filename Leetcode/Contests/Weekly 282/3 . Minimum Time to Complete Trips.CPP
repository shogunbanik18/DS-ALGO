class Solution {
public:
    
    // Brute force
    // Linear Search 
    // tc: o(n^2)
    //   sc:o(1)
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        int n =time.size();
        long long ans;
        for(int t=0;t<n;t++)
        {
            long long count=0;
            for(int i=0;i<n;i++)
            {
                count+= t/time[i];
            }
            if(count>=totalTrips)
            {
                ans=t;
                break;
            }
        }
        return ans;
    }
    
    // optimisation using binary Search 
    // tc:o(logn)*n
    //   sc:o(1)
    long long counttime(long long mid,vector<int>&time)
    {
        long long count=0;
        for(auto x:time)
        {
            count+=mid/x;
        }
        return count;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        long long low =0;
        long long high =1e14;
        long long ans=high;
        while(low<=high)
        {
            long long mid =(low+high)/2;
            if(counttime(mid,time)>=totalTrips)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
    
};
