// ########## Amazon ##########
class Solution {
public:
    // using stack 
    // tc:o(n)
    // sc:o(n) stack space
    bool isValid(string s)
    {
        bool ans=true;
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' or s[i]=='[' or s[i]=='{')
            {
                st.push(s[i]);
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
        }
       if(!st.empty())
       {
           ans=false;
       }
        return ans;
    }
};
