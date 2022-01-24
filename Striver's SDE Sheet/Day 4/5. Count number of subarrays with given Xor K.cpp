    // brute force 
    // can be solved using naive appraoch 
    // simliar to brute force of kadanes algo
    // tc:O(n^2)
    // sc:O(1)
int Solution::solve(vector<int> &A, int B)
{
    long long count=0;
    for(int i=0;i<A.size();i++)
    {
        int xorr=0;
        for(int j=0;j<A.size();i++)
        {
            xorr^=A[i];
            if(xorr==B)
            {
                count++;
            }
        }
    }
    return count;
}

// Most optimal approach using hashmap
// tc:O(nlogn)
// sc:o(n)
int Solution::solve(vector<int> &A, int B)
{
    unordered_map<int,int> mp;
    int count=0;
    int xorr=0;
    for(auto it:A)
    {
        xorr=xorr^it;
        if(xorr==B)
        {
            count++;
        }
        if(mp.find(xorr^B)!=mp.end())
        {
            count+=mp[xorr^B];
        }
        mp[xorr]+=1;
    }
    return count;
}
