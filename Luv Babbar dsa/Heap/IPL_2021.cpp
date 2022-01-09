class Solution {
  public:
    // vector<int> max_of_subarrays(vector<int> arr, int n, int k)
    // {
    //     // using priority queue
    //     vector<int>v;
    //     int l=0;
    //     int end=k-1;
    //     priority_queue<int>pq;
    //     while(end!=n)
    //     {
    //         for(int i=l;i<=end;i++)
    //         {
    //             pq.push(arr[i]);
    //         }
    //         v.push_back(pq.top());
    //         // pq.pop();
    //         l++;
    //         end++;
    //     }
    //     return v;
    //     // your code here
    // }
    
     vector<int> max_of_subarrays(vector<int> arr, int n, int k)
     {
         vector<int>ans;
         deque<int>dq;
         int i=0;
         while(i<n)
         {
             while(!dq.empty() and dq.front() == i-k)
             {
                 dq.pop_front();
             }
             while(!dq.empty() and arr[dq.back()]<arr[i])
             {
                 dq.pop_back();
             }
             dq.push_back(i);
             if(i>=k-1)
             {
                 ans.push_back(arr[dq.front()]);
             }
             i++;
         }
         return ans;
     }
  };
