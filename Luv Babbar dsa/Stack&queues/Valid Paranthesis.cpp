// Valid Paranthesis 
bool valid(string s)
{
    bool ans=true;
    stack<char>st;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(' or s[i]=='{' or s[i]=='[')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
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
        else if(s[i]=='}')
        {
            if(!st.empty() and st.top()=='{')
            {
                st.pop();
            }
            else
            {
                ans=false;
                break;
            }
        }
        else if(s[i]==']')
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
    // code here
}
