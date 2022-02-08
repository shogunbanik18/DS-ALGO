class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    // Intuition  for Greedy Approach: 
        // sorting the end time because we need meeting that ends faster
        // as it will benifit us and maximum meeting can be done in time
        // so sorting the end array and then checking the start time of next pair
        // and the end time of previous pair 
    
    // tc:o(nlogn)+o(n)
    // sc:o(n) for the vector 
    static bool comp(pair<int,int>a,pair<int,int>b)
    {
        if(a.second==b.second)
        {
            return a.first<b.first;
        }
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
       vector<pair<int,int>>v(n);
       for(int i=0;i<n;i++)
       {
           v[i]={start[i],end[i]};
       }
       sort(v.begin(),v.end(),comp);
       int i=0;
       int j=1;
       int count=1;
       while(j<n)
       {
           if(v[i].second<v[j].first)
           {
               count++;
               i=j;
               j++;
           }
           else
           {
               j++;
           }
       }
       return count;
        // Your code here
    }
};
