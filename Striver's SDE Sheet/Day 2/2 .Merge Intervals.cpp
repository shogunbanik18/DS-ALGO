class Solution {
public:
    
    // Brute force
    //   tc :O(NLOGN +N^2)
//     irst check whether the array is sorted or not.If not sort the array. Now linearly iterate over the array and then check for all of its next intervals whether they are overlapping with the interval at the current index. Take a new data structure and insert the overlapped interval.
//   If while iterating if the interval lies in the interval present in the data structure simply continue and move to the next interval.
    
    tc : O(NlogN +N)
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>>mergeintervals;
        
        // check for edge case 
        if(intervals.size()==0)
        {
            return mergeintervals;
        }
        
        // sorting 
        sort(intervals.begin(),intervals.end());
        vector<int> temp=intervals[0];
        
        for(auto x:intervals)
        {
            if(x[0]<=temp[1])
            {
                temp[1]=max(temp[1],x[1]);
            }
            else
            {
                mergeintervals.push_back(temp);
                temp=x;
            }
        }
        // last resultant interval
        mergeintervals.push_back(temp);
        return mergeintervals;
    }
    
    
     vector<vector<int>> merge(vector<vector<int>>& intervals) 
     {
         vector<vector<int>>ans;
         sort(intervals.begin(),intervals.end());
         int x=intervals[0][0];
         int y=intervals[0][1];
         for(auto it:intervals)
         {
             if(it[0]<=y)
             {
                 y=max(y,it[1]);
             }
             else
             {
                 ans.push_back({x,y});
                 x=it[0];
                 y=it[1];
             }
         }
         ans.push_back({x,y});
         return ans;
     }
};
