#include<bits/stdc++.h>
using namespace std;

void reverseSentence(string s)
{
    stack<string>st;
    
    for(int i=0;i<s.length();i++)
    {
        string word="";
        while(s[i]!=' ' and i<s.length())
        {
            word=word+s[i];
            i++;
        }
        st.push(word);
    }
    
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    
}

 int main()
 {
     stack<int>st;
     string s="Hey, how are you doing?";
     reverseSentence(s);
     return 0;
 }
