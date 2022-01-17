class Solution {
public:
    
    // tc: O(N)
    bool wordPattern(string pattern, string s) 
    {
        vector<string>words;
        string res="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                words.push_back(res);
                res="";
            }
            else
            {
                res+=s[i];
            }
        }
        // for putting the last word 
        words.push_back(res);
        
        if(words.size()!=pattern.size())
        {
            return false;
        }
        
        unordered_map<char,string>mp;
        set<string>set;
        for(int i=0;i<pattern.size();i++)
        {
            if(mp.find(pattern[i])!=mp.end())
            {
                if(mp[pattern[i]]!=words[i])
                {
                    return false;
                }
            }
            else
            {
                if(set.count(words[i])>0)
                {
                    return false;
                }
                mp[pattern[i]]=words[i];
                set.insert(words[i]);
            }
        }
        return true;
    }
};
