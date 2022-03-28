// Using Hashing
// tc : o(s) + o(t)
// sc : o(n) or(nlogn)
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        map<char,int>mp;
        
        // check for same size 
        if(s.size() != t.size())
        {
            return false;
        }
        
        // if same size then 
        for(auto a : s)
        {
            mp[a]++;
        }
        
        for(auto b : t)
        {
            mp[b]--;
        }
        
        for(auto x : mp)
        {
           if(x.second!=0)
           {
               return false;
           }
        }
        
        return true;
    }
};



// // Using Hashing
// // tc : o(s) + o(t)
// // sc : o(n) or(nlogn)
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        map<char,int>mp;
        
        // check for same size 
        if(s.size() != t.size())
        {
            return false;
        }
        
        // if same size then 
        for(int i=0;i<s.size();i++)
        {
            mp[ s[i] ]++;
            mp[ t[i] ] --; 
        }
        
        for(auto x : mp)
        {
           if(x.second!=0)
           {
               return false;
           }
        }
        
        return true;
    }
};

// using simple sorting 
// tc : o(nlogn) + o(mlogm)
// sc : o(1)
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};
