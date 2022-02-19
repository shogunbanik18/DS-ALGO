class Solution {
public:
    long long minimumRemoval(vector<int>& beans)
    {
        long long ans =1e18;
        sort(beans.begin(),beans.end());
        long long sum=0;
        for(auto x : beans)
        {
            sum+=x;
        }
        
        long long n=beans.size();
        for(int i=0;i<n;i++)
        {
            long long change =sum -(n-i)*(long long)beans[i]*1ll;
            ans = min(ans,change);
        }
        return ans;
    }
};
