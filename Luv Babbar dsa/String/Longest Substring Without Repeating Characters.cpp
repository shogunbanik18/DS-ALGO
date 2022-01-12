class Solution {
public:
    // using slidin window and Hashing 
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set<char>set;
        int n=s.size();
        int i=0;
        int j=0;
        int x=0;
        while(i<n and j<n)
        {
            if(set.find(s[j])==set.end())
            {
                set.insert(s[j]);
                j++;
                x=max(x,j-i);
            }
            else
            {
                set.erase(s[i++]);
            }
        }
        
        return x;
    }
};
