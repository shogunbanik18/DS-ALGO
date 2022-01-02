class Solution {
  public:
    // tc:O(N)
    // sc: O(N)
    int kThSmallestFactor(int N , int K)
    {
        vector<int>v;
        for(int i=1;i<=N;i++)
        {
            if(N%i==0)
            {
                v.push_back(i);
            }
        }
        
        if(K>v.size())
        {
            return -1;
        }
        int ans=v[K-1];
        return ans;
        // code here
    }
    
    // tc:O(N)
    // sc:O(1)
    int kThSmallestFactor(int N , int K)
    {
        int count=0;
        for(int i=1;i<=N;i++)
        {
            if(N%i==0)
            {
                count++;
            }
            if(K==count)
            {
                return i;
            }
        }
        return -1;
    }
};
