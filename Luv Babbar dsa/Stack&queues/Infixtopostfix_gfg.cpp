class Solution
{
    public:
    //Function to convert an infix expression to a postfix expression.
    int precedance(char c)
    {
        if(c=='^')
        {
            return 3;
        }
        
        else if(c=='/' or c=='*')
        {
            return 2;
        }
        
        else if(c=='+' or c=='-')
        {
            return 1;
        }
        
        else
        {
            return -1;
        }
    }
    
    string infixToPostfix(string s)
    {
        stack<char>st;
        string res="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
            }
            
            else if((s[i]>='a' and s[i]<='z') or (s[i]>='A'&&s[i]<='Z' ))
            {
                res=res+s[i];
            }
            
            else if(s[i]==')')
            {
                while(!st.empty() and st.top()!='(')
                {
                    res=res+st.top();
                    st.pop();
                }
                if(!st.empty())
                {
                    st.pop();
                }
            }
            
            else
            {
                while(!st.empty() and precedance(st.top())>=precedance(s[i]))
                {
                    res=res+st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            res=res+st.top();
            st.pop();
        }
        return res;
    }
};
