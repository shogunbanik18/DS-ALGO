// using priority queue concept 
// max heap 

class Solution{
public:
    int minValue(string s, int k)
    {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        
        // max headp 
        priority_queue<int>maxh;
        for(auto x: mp)
        {
            maxh.push(x.second);
        }
        
        while(maxh.size()>0 and k--)
        {
            int x=maxh.top();
            maxh.pop();
            x--;
            maxh.push(x);
        }
        
        int sum=0;
        while(maxh.size()>0)
        {
            sum+=pow(maxh.top(),2);
            maxh.pop();
        }
        return sum;
        // code here
    }
};
