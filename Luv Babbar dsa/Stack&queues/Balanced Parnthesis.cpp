#include<bits/stdc++.h>
using namespace std;

bool isvalid(string s)
{
    bool ans=true;
    stack<char>st;
    int n=s.length();
    
    for(int i=0;i<n;i++)
    {
        if((s[i]=='{') or (s[i]=='[') or (s[i]=='('))
        {
            st.push(s[i]);
        }
        
        else if(s[i]=='}')
        {
            if(!st.empty() and st.top()=='{')
            {
                st.pop();
            }
        }
        
        else if(s[i]==']')
        {
            if(!st.empty() and st.top()=='[')
            {
                st.pop();
            }
        }
        
        else if(s[i]==')')
        {
            if(!st.empty() and st.top()=='(')
            {
                st.pop();
            }
        }
        
        else
        {
            ans=false;
            break;
        }
    }
    
    if(!st.empty())
    {
        return false;
    }
    
    return ans;
}

int main()
{
    string s="{[()]}";
    if(isvalid(s))
    {
        cout<<"Valid String"<<endl;
    }
    else
    {
        cout<<"Invalid String!"<<endl;
    }
    return 0;
}


// gfg Code

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        bool ans=true;
        int n=x.size();
        stack<char>st;
        
        for(int i=0;i<n;i++)
        {
            if(x[i]=='{' or x[i]=='[' or x[i]=='(')
            {
                st.push(x[i]);
            }
            
            else if(x[i]=='}')
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
            
            else if(x[i]==']')
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
            
            else if(x[i]==')')
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
            return false;
        }
        return ans;
        // Your code here
    }
};
