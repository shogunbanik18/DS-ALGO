class Solution {
public:
    // tc:o(n)
    // sc:o(n)
    bool isValid(string s) 
    {
        stack<char>st;
        int n=s.size();
        bool ans=true;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' or s[i]=='{' or s[i] =='[')
            {
                st.push(s[i]);
            }
            
            else if(s[i]==')' )
            {
                if(!st.empty() and st.top()=='(')
                {
                    st.pop();
                }
                else
                {
                     ans=false;
                    break;
                }
            }
            else if(s[i]=='}' )
            {
                if(!st.empty() and st.top()=='{' )
                {
                    st.pop();
                }
                else
                {
                    ans=false;
                    break;
                }
            }
            
            else if(s[i]==']' )
            {
                if(!st.empty() and st.top()=='[')
                {
                    st.pop();
                }
                else
                {
                    ans=false;
                    break;
                }
            }
        }
        
        if(!st.empty())
        {
            ans=false;
        }
        return ans;
    }
};

// striver's approach 
class Solution {
public:
    // tc:o(n)
    // sc:o(n)
    bool isValid(string s) 
    {
        stack<char>st;
        int n=s.size();
        bool ans=true;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' or s[i]=='{' or s[i] =='[')
            {
                st.push(s[i]);
            }
            
            else 
            {
                if(st.empty())
                {
                    return false;
                }
                char c=st.top();
                st.pop();
                if((s[i]==')' and c=='(') or (s[i]=='}' and c=='{') or (s[i]==']' and c=='[') )
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
