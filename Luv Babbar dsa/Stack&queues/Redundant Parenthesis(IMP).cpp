#include<bits/stdc++.h>
using namespace std;

bool checkredun(string &str)
{
    stack<char>st;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==')')
        {
            char top=st.top();
            st.pop();
            
            bool flag=true;
            
            while(!st.empty() and top!='(')
            {
                if(top=='+' or top=='-' or top=='*' or top=='/')
                {
                    flag=false;
                }
                top=st.top();
                st.pop();
            }
            
            // operators not found
            if(flag==true)
            {
                return true;
            }
        }
        else
        {
            st.push(str[i]);
        }
    }
    return false;
}

void findRedundant(string &str)
{
    bool ans=checkredun(str);
    if(ans==true)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}

int main()
{
    string s1="((a+b))";
    findRedundant(s1);
    
    string s2 = "(a+(b)/c)";
    findRedundant(s2);
 
    string s3 = "(a+b*(c-d))";
    findRedundant(s3);
    return 0;
}



// alter 

bool checkredun(string &str)
{
    stack<char>st;
    bool ans=false;
    for(int i=0;i<str.size();i++)
    {
       if(str[i]=='+' or str[i]=='-' or str[i]=='*' or str[i]=='/')
       {
           st.push(str[i]);
       }
       else if(str[i]=='(')
       {
           st.push(str[i]);
       }
       
       else if(str[i]==')')
       {
           if(st.top()=='(')
           {
               ans=true;
           }
           while(st.top()=='+' or st.top()=='-' or st.top()=='*' or st.top()=='/')
           {
               st.pop();
           }
           st.pop();
       }
    }
    cout<<ans<<endl;
}

int main()
{
    string s1="((a+b))";
    // findRedundant(s1);
    checkredun(s1);
    
    string s2 = "(a+(b)/c)";
    // findRedundant(s2);
    checkredun(s2);
    
    string s3 = "(a+b*(c-d))";
    // findRedundant(s3);
    checkredun(s3);
    
    return 0;
}
