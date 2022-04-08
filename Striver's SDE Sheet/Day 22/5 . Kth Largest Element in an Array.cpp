// using sorting 
// tc : o(nlogn)
// sc : o(1)
// class Solution 
// {
// public:
//     int findKthLargest(vector<int>& nums, int k) 
//     {
//         sort(nums.begin(),nums.end());
        
//         int n = nums.size();
//         int x = n -k;
        
//         return nums[x];
//     }
// };

// using priority queue
// tc : o(n * logn)
// sc :o(1)
class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int> pq;
       
        for(auto x : nums)
        {
            pq.push(x);
        }
        
        int count = 0;
        int ans = 0;
        
        while(!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            count++;
            
            if(count==k)
            {
                ans = x;
                break;
            }
            
        }
    
        return ans;
    }
};
