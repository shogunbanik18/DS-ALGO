#include<bits/stdc++.h>
using namespace std;

int prefixsum(string s)
{
    stack<int>st;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]>='0' and s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        // for operator case 
        else 
        {
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();
            
            
            if(s[i]=='+')
            {
                st.push(op1+op2);
            }
            
            else if(s[i]=='-')
            {
                st.push(op1-op2);
            }
            
            else if(s[i]=='*')
            {
                st.push(op1*op2);
            }
            
            else if(s[i]=='/')
            {
                st.push(op1/op2);
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
    // prefix : -+7*45+20
    string s= "-+7*45+20";
    cout<<prefixsum(s)<<endl;
    return 0;
}


 
            // Alter
            // // use of switch case 
            // switch(s[i])
            // {
            //     case '+':
            //     st.push(op1+op2);
            //     break;
                
            //     case '-':
            //     st.push(op1-op2);
            //     break;
                
            //     case '*':
            //     st.push(op1*op2);
            //     break;
                
            //     case '/':
            //     st.push(op1/op2);
            //     break;
                
            //     default:
            //     break;
            // }
