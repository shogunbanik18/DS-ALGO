// Minimum Remove to Make Valid Parentheses
// using traversing approach solution
// tc: o(n) + o(n) + o(n)
// sc : o(1)
class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        // teaversing from front 
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(' )
            {
                count++;
            }
            else if(s[i] == ')')
            {
                if(count==0)
                {
                    s[i]='#';
                }
                else
                {
                    count--;
                }
            }
        }
        
        count=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==')')
            {
                count++;
            }
            else if(s[i]=='(')
            {
                if(count==0)
                {
                    s[i]='#';
                }
                else
                {
                    count--;
                }
            }
        }
        
        string res="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='#')
            {
                res+=s[i];
            }
        }
        return res;
    }
};
    

// using stack ds 
// tc: o(n)
// sc: o(n)
class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<int>st;
        
        int n=s.size();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            
            else if (s[i]==')' )
            {
                if(st.empty()==true)
                {
                    s[i]= '#';
                }
                else
                {
                   st.pop();  
                } 
            }
        }
        
        while(!st.empty())
        {
            s[st.top()] = '#';
            st.pop();
        }
        
        string res;
        for(int i=0;i<n;i++)
        {
            if(s[i]!='#')
            {
                res+=s[i];
            }
        }
        return res;
        
    }
};
