class Solution {
public:
    // tc:O(glogg)+O(slogs)
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        int count=0;
        int i=0,j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i<g.size() and j<s.size())
        {
            if(s[j]>=g[i])
            {
                count++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return count;
    }
};
