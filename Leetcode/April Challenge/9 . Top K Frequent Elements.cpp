// using the conceot of maxheap 
// tc : o(nlogn)
// sc : o(1)
class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        priority_queue< pair<int,int> > pq;
        map<int,int> mp;
        
        for(auto x : nums)
        {
            mp[x]++;
        }
        
        for(auto x : mp)
        {
            pq.push({x.second, x.first});
        }
        
        vector<int>v;
        int count =0,ans=0;
        while(!pq.empty())
        {
            auto a = pq.top();
            pq.pop();
            
            v.push_back(a.second);
            count++;
            
            if(count==k)
            {
                break;
            }
        }
        return v;
    }
};
