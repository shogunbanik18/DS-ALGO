class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals)
    {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int left=-1,right=-1,res=0;
        for(auto x:intervals)
        {
            if(x[0]>left and x[1]>right)
            {
                left=x[0];
                res+=1;
            }
            right=max(right,x[1]);
        }
        return res;
    }
};
