// Wrong Approach 
// class Solution {
// public:
//     int findsum(vector<int>&nums)
//     {
//         int sum=0;
//         for(auto x:nums)
//         {
//             sum += x;   
//         } 
//         return sum;
//     }
    
//     int halveArray(vector<int>& nums) 
//     {
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         float sum1 = (findsum(nums));
//         float mid = sum1/2;
        
//         float to_find = sum1 - mid;
        
//         int count=0;
//         while(findsum(nums) >= to_find)
//         {
//             count++;
//             nums[n-1] = nums[n-1]/2;
        
//         }
//         cout<<to_find<<endl;
//         return count;
//     }
// };

// Priority queue based Approach
// tc : o(nlogn)
// sc: o(1)
class Solution {
public:
    
    double findsum(vector<int>&nums)
    {
        double sum1=0;
        for(auto x:nums)
        {
            sum1 += (double)x;   
        } 
        return sum1;
    }
    
    int halveArray(vector<int>& nums) 
    {
        int n = nums.size();
        int count=0;
        
        double sum = findsum(nums);
        double halfsum = sum/2;
        
        priority_queue<double> pq;
        
        for(auto x : nums)
        {
            pq.push((double)x);
        }
        
        while(pq.size()!=0 and sum>halfsum)
        {
            double item = pq.top();
            pq.pop();
            
            sum -= item /2.0;
            item = item/2.0;
            
            count++;
            if(item>0)
            {
                pq.push(item);
            }
        }
        return count;
    }
};
