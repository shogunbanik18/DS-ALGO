// tc :O(n)
// sc: O(1)
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        vector<int>v;
        sort(candies,candies+N);
        int mini=0;
        int i=0;
        int j=N-1;
        while(i<=j)
        {
            mini+=candies[i];
            i++;
            j=j-K;
        }
        
        sort(candies,candies+N,greater<int>());
        int maxi=0;
        int l=0;
        int r=N-1;
        while(l<=r)
        {
            maxi+=candies[l];
            l++;
            r=r-K;
        }
        
        v.push_back(mini);
        v.push_back(maxi);
        return v;
        
        // Write Your Code here
    }
};
