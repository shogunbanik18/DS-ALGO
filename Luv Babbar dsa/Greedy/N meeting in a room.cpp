class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>v;
        int maxmeet=1;
        int count=1;
        for(int i=0;i<n;i++)
        {
            v.push_back({end[i],start[i]});
        }
        sort(v.begin(),v.end());
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(v[j].first<v[i].second)
            {
                count++;
                j=i;
            }
        }
        return count;
    }
};
