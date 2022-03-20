// using sorting and searching 
// tc :o(nlogn)
// sc :o (1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        sort(nums.begin(),nums.end());
        
        int x = nums.size()-k;
        return nums[x];
    }
};

// using priority queue 
// tc : o(nlogk)
// sc : o(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int>pq;
        for(auto x :nums )
        {
            pq.push(x);
        }
        
        // cout<<pq.top()<<endl;
        
        int x = k-1;
        while(x--)
        {
            pq.pop();
        }
        
        int a = pq.top();
        return a;
    }
};
