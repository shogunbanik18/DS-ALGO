class Solution {
public:
    
    // Brute force
    //   tc :O(NLOGN +N^2)
//     irst check whether the array is sorted or not.If not sort the array. Now linearly iterate over the array and then check for all of its next intervals whether they are overlapping with the interval at the current index. Take a new data structure and insert the overlapped interval.
//   If while iterating if the interval lies in the interval present in the data structure simply continue and move to the next interval.
      // Brute force 
    // tc:o(nlogn)+o(n*n)
    // sc:o(n)
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
           if(n<=1)
            {
                return intervals;
            }
        int m=intervals[0].size();
    
        vector<vector<int>>res;
        for(int i=0;i<n;i++)
        {
            int a=intervals[i][0];
            int b=intervals[i][1];
            for(int j=i+1;j<m;j++)
            {
                int c=intervals[j][0];
                int d=intervals[j][1];
                
                if(b>=c)
                {
                    b=max(b,d);
                    i=j;
                }
            }
            res.push_back({a,b});
        }
        return res;
    }
    
    
    
    
//             Solution 2: Optimal approach

// Approach: Linearly iterate over the array if the data structure is empty insert the interval in the data structure. 
//         If the last element in the data structure overlaps with the current interval we merge the intervals by updating the last element in the data structure, 
//         and if the current interval does not overlap with the last element in the data structure simply insert it into the data structure.

// Intuition: Since we have sorted the intervals, the intervals which will be merging are bound to be adjacent. 
//         We kept on merging simultaneously as we were traversing through the array and when the element was non-overlapping 
//         we simply inserted the element in our data structure.
    
    
//     tc : O(NlogN +N)
//     sc:o(n)
   class Solution {
public:
    
    
    // shaadndaar question 
    // Optimised Aproach 
    // tc:o(nlogn)+o(n)
    // sc:o(n)
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        if(intervals.size()==0)
        {
            return ans;
        }
        
        vector<int>temp =intervals[0];
        
        for(auto x: intervals)
        {
            if(x[0]<=temp[1])
            {
                temp[1]=max(temp[1],x[1]);
            }
            else
            {
                ans.push_back(temp);
                temp=x;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
    
//     Alter Approach otimised
//  Space optimised 
     vector<vector<int>> merge(vector<vector<int>>& intervals) 
     {
         vector<vector<int>>ans;
         sort(intervals.begin(),intervals.end());
         if(intervals.size()==0)
         {
             return ans;
         }
         int a =intervals[0][0];
         int b =intervals[0][1];
         for(auto x :intervals)
         {
             if(x[0]<=b)
             {
                 b=max(b,x[1]);
             }
             else
             {
                 ans.push_back({a,b});
                 a=x[0];
                 b=x[1];
                 
             }
         }
         ans.push_back({a,b});
         return ans;
     }
};
