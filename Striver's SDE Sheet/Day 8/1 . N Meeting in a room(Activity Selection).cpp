
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    // Intuition  for Greedy Approach: 
        // sorting the end time because we need meeting that ends faster
        // as it will benifit us and maximum meeting can be done in time
        // so sorting the end array and then checking the start time of next pair
        // and the end time of previous pair 
    
    // tc:o(nlogn)+o(n)
    // sc:o(n) for the vector 
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
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
        int i=1;
        int j=0;
        int count=1;
        while(i<n)
        {
            if(v[i].first>v[j].second)
            {
                count++;
                j=i;
                i++;
            }
            else
            {
                i++;
            }
        }
        return count;
    }
};


// Coding Ninjas 
// TC : O(n) +O(n log n) + O(n) ~O(n log n)
// sc: o(n)
#include<bits/stdc++.h>
struct meeting{
	int start;
	int end;
	int pos;
};

bool comp(struct meeting m1 ,struct meeting m2)
{
	if(m1.end < m2.end)
	{
		return true;
	}
	else if(m1.end>m2.end)
	{
		return false;
	}
	else if(m1.pos<m2.pos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

vector<int> maximumMeetings(vector<int> &s, vector<int> &e) {
	int n = s.size();
	struct meeting meet[n];
	
	for(int i=0;i<n;i++)
	{
		meet[i].start = s[i];
		meet[i].end = e[i];
		meet[i].pos = i+1;
	}
	
	sort(meet,meet+n,comp);
	
	vector<int>ans;
	int limit = meet[0].end;
	ans.push_back(meet[0].pos);
	
// 	last mein humhe position chahiye bas
	for(int i=1;i<n;i++)
	{
		if(meet[i].start>limit)
		{
			limit = meet[i].end;
			ans.push_back(meet[i].pos);
		}
	}
	return ans;
}
