// Postfix evaluation 
// tc :O(l)
// l is the length of string 
#include<bits/stdc++.h>
using namespace std;

int postfix(string s)
{
    stack<int>st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0' and s[i]<='9')
        {
            // converting cahr to integer using ASCII value 
            st.push(s[i]-'0');
        }
        else
        {
            int opt2=st.top();
            st.pop();
            int opt1=st.top();
            st.pop();
            
            if(s[i]=='+')
            {
                st.push(opt1+opt2);
            }
            
            else if(s[i]=='-')
            {
                st.push(opt1-opt2);
            }
            
            else if(s[i]=='*')
            {
                st.push(opt1*opt2);
            }
            
            else if(s[i]=='/')
            {
                st.push(opt1/opt2);
            }
            
            else if(s[i]=='^')
            {
                st.push(pow(opt1,opt2));
            }
            else
            {
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    string s="46+2/5*7+";
    cout<<postfix(s)<<endl;
    return 0;
}



// gfg code 

class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // postfix expression
        // tc: O(S)
        stack<int>st;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]>='0' and S[i]<='9')
            {
                // ASCII VALUE OF STRING 
                st.push(S[i]-'0');
            }
            else
            {
                int opt2=st.top();
                st.pop();
                int opt1=st.top();
                st.pop();
                
                if(S[i]=='+')
                {
                    st.push(opt1+opt2);
                }
                
                else if(S[i]=='-')
                {
                    st.push(opt1-opt2);
                }
                
                else if(S[i]=='*')
                {
                    st.push(opt1*opt2);
                }
                
                else if(S[i]=='/')
                {
                    st.push(opt1/opt2);
                }
                
                else if(S[i]=='^')
                {
                    st.push(pow(opt1,opt2));
                }
                
                else
                {
                    break;
                }
            }
        }
        return st.top();
        // Your code here
    }
};
