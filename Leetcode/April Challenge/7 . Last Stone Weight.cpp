// tc : o(n) or o(nlogn)
// sc : o(1)
class Solution
{
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        int n = stones.size();
        
        priority_queue<int>pq;
        
        for(auto x : stones)
        {
            pq.push(x);
        }
        
        // Debug 
        // while(!pq.empty())
        // {
        //     int a = pq.top();
        //     cout<<a<<" ";
        //     pq.pop();
        // }
        // cout<<endl;
        
        
        int  ans =0;       
        while(!pq.empty())
        {
            if(pq.size()==1)
            {
                ans = pq.top();
                break;
            }
            
            int a = pq.top();
            pq.pop();
            
            int b = pq.top();
            pq.pop();
            
            if(a!=b)
            {
                pq.push(a-b);
            }
        }
        
        return ans;
    }
};
