class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if(s.size()!=t.size())
        {
            return false;
        }
        unordered_map<char,int>counts;
        for(int i=0;i<s.size();i++)
        {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for(auto x:counts)
        {
            if(x.second)
            {
                return false;
            }
        }
        return true;
    }
    
//   Alter Approach 
    bool isAnagram(string s, string t)
    {
       sort(s.begin(),s.end());
       sort(t.begin(),t.end());
       return s==t;
    }
    
};
