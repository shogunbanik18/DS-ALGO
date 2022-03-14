class Solution {
public:
    // counting the no. of set bits 
    // use of and operator 
    // tc: o(n)
    // sc:o(1)
    vector<int> countBits(int n) 
    {
        vector<int>v;
        for(int i=0;i<=n;i++)
        {
            int res=i;
            int count=0;
            while(res>0)
            {
                count+=res&1;
                res=res/2;
            }
            v.push_back(count);
        }
        return v;
    }
};
