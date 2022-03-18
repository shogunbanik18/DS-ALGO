class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        set<char>st;
        int n=s.size();
        
        for(int i=0;i<n;i++)
        {
            st.insert(s[i]);
        }
        
        string res="";
        for(auto x: st)
        {
            res +=x;
        }
        
        return res;
    }
};


// using freq array and vis array
// tc: o(n)
// sc: o(n)
// using hashing 
class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        map<char,int> freq;
        map<char,bool> vis;
        
        for(auto x: s)
        {
            freq[x]++;
        }
        
        
        string res="";
        for(auto x: s)
        {
            freq[x]--;
            if(vis[x]==true)
            {
                continue;
            }
            
            else
            {
                while(!res.empty() and res.back()>x and freq[res.back()]>0)
                {
                    vis[res.back()]=false;
                    res.pop_back();
                }
                vis[x]=true;
                res += x;
            }
        }
        return res;
    }
};


// using frequency array  
// tc : o(n)
// sc : o(n)
class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> freq(26,0);
        vector<int> vis(26,0);
        stack<char>st;
        // storing the indexes 
        
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a']++;
        }
        
        
        string res="";
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a'] --;
            if(vis[s[i]-'a'] ==1)
            {
               continue; 
            }
            
            else 
            {
                while(!res.empty() and s[i]<res.back() and freq[res.back()-'a']>0 )
                {
                    vis[res.back()-'a']=0;
                    res.pop_back();
                }

                res += s[i];
                vis[s[i]-'a'] =1;
            }
            
        }
        
        return res;
    }
};
