class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string,int>mp;
        int max1=INT_MIN;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
            max1=max(max1,mp[arr[i]]);
        }
        
        pair<string,int>ans;
        ans.second=INT_MIN;
        
        for(auto x:mp)
        {
            if(x.second==max1)
            {
                continue;
            }
            
            if(ans.second<x.second)
            {
                ans={x.first,x.second};
            }
        }
        return ans.first;
    }
};
