// using Brute Force 
// Two pointer approach 
// tc : o(n^k)
// sc : o(1)
// class Solution
// {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k)
//     {
//         int n =nums.size();
//         vector<int>v;
        
//         for(int i=0;i<=n-k;i++)
//         {
//             int maxi = nums[i];
            
//             for(int j = i; j<= (i+k-1);j++)
//             {
//                 maxi = max(maxi,nums[j]);
//             }
            
//             v.push_back(maxi);
            
//         }
//         return v;
//     }
// };

// // // using priority queue 
// // // tc : o(nlogk)
// // // sc : o(1)
// class Solution
// {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k)
//     {
//         int n = nums.size();
//         vector<int>v;
        
//         // maxheap
//         priority_queue< pair<int,int>> pq;
        
//         for(int i = 0;i<k;i++)
//         {
//             pq.push({nums[i],i});
//         }
        
//         v.push_back(pq.top().first);
        
//         for(int i= k;i<n;i++)
//         {
//             pq.push({nums[i],i});
            
            
//             // current window is from [i-k+1 ,i ]
//             while(! (pq.top().second >(i-k) ))
//             {
//                 pq.pop();
//             }
            
//             v.push_back(pq.top().first);
//         }
        
//         return v;
//     }
// };


// // using dequeue  
// // tc : o(n) + o(n)
// // sc : o(1) amortised
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<int>v;
        
        deque <int> dq;
        
        for(int i=0;i<n;i++)
        {
            // out of bound 
            if(!dq.empty() and  dq.front()== i-k)
            {
                dq.pop_front();
            }
            
            while(!dq.empty() and nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if(i>=k-1)
            {
                v.push_back(nums[dq.front()]);
            }
        }
         
        return v;      
    }
};
