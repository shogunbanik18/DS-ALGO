class Solution {
public:
    // using binary search approach 
    bool caneatintime(vector<int>&piles,int k,int h)
    {
        int hours=0;
        for(int pile:piles)
        {
            int div=pile/k;
            hours+=div;
            if(pile%k!=0)
            {
                hours++;
            }
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int left=1;
        int right=INT_MAX;
        
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(caneatintime(piles,mid,h))
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return left;
    }
};
