// using the concept of priority queue
// tc : o(nlogn)
// sc : o(1)
class KthLargest 
{
public:
    
    // using minheap 
    priority_queue<int , vector<int> , greater<int> > pq;
    int size = 0;
    
    KthLargest(int k, vector<int>& nums) 
    {
        size = k;
        
        for(auto x : nums)
        {
            pq.push(x);
            
            if(pq.size()>size)
            {
                pq.pop();
            }
        }
    }
    
    int add(int val) 
    {
        pq.push(val);
        
        if(pq.size()> size)
        {
            pq.pop();
        }
        
        int ans = pq.top();
        return ans;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
