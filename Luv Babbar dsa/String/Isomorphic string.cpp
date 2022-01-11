class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
//         int n=s.length();
//         int m1[256],m2[256];
//         for(int i=0;i<256;i++)
//         {
//             m1[i]=m2[i]=-1;
//         }
        
//         for(int i=0;i<n;i++)
//         {
//             if(m1[s[i]]!=m2[t[i]])
//             {
//                 return false;
//             }
//              m1[s[i]] = m2[t[i]] = i;
//         }
//         return true;
        
        
        int n=s.size();
        int m=t.size();
        // base case
        if(n!=m)
        {
            return false;
        }
        
        int m1[265]={0};
        int m2[256]={0};
        for(int i=0;i<n;i++)
        {
            if(!m1[s[i]] and !m2[t[i]])
            {
                // mapping 
                m1[s[i]]=t[i];
                m2[t[i]]=s[i];
            }
            else if(m1[s[i]]!=t[i])
            {
                return false;
            }
        }
        return true;
    }
};

// gfg 
class Solution
{
    public:
    // isomorphic strings
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        int n=str1.size();
        int m=str2.size();
        // base case
        if(n!=m)
        {
            return false;
        }
        
        int m1[256]={0};
        int m2[256]={0};
        for(int i=0;i<n;i++)
        {
             if(!m1[str1[i]] and !m2[str2[i]])
             {
                 m1[str1[i]]=str2[i];
                 m2[str2[i]]=str1[i];
             }
             else if(m1[str1[i]]!=str2[i])
             {
                 return false;
             }
        }
        return true;
        // Your code here
    }
};
