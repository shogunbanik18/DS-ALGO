// using the concept of binary search on Answer 
// similar to book allocation with variation in search space
class Solution 
{
public:

    bool check(int mid , vector<int>& arr ,long long k )
    {
        long long n = arr.size();
        long long count =0;
        
        for(int i=0 ; i<n;i++)
        {
            count += (arr[i]) /mid;
        }
        
        // cout<<count<<" ";
        if(count>=k)
        {
            return true;
        }
        return false;
    }
    
    int maximumCandies(vector<int>& candies, long long k)
    {
       
        int maxi =INT_MIN;
        
        for(auto x : candies)
        {
            maxi = max(maxi,x);
        }

        // Minimum piles can be 1 
        int low = 1;
        
        // maximum piles can be max of the element
        int high = maxi;
        // cout<<low << " "<<high<<endl;
        
        int ans =0;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(check (mid , candies , k) )
            {
                ans =  mid ;
                low = mid + 1;
            }
            else
            {
                high = mid-1;
            }
        }
        
        return ans;
    }
};
