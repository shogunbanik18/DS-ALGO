// Function to find square root
// x: element to find square root
class Solution{
  public:
    // using stl library
    long long int floorSqrt(long long int x) 
    {
        return sqrt(x);
    }
    
    // using basic approach 
    // tc:O(N)
    long long int floorSqrt(long long int x) 
    {
        // for return ing floor value 
        long long int count=0;
        long long int i=1;
        while(i*i<=x)
        {
            count++;
            i++;
        }
        return count;
    }
    
    // using binary search approach
    // O(LogN)
    long long int floorSqrt(long long int x)
    {
        long long int low=0;
        long long int high=x;
        long long int ans;
         long long int mid =(low+high)/2;
        
        while(low<=high)
        {
            long long int s=mid*mid;
            if(s>x)
            {
                high=mid-1;
            }
            else
            {
                ans=mid;
                low=mid+1;
            }
            mid =(low+high)/2;
        }
        return ans;
    }
};
