#include<bits/stdc++.h>
using namespace std;

// use of call stack and stack 
void insertatbottom(stack<int>&st,int ele)
{
    if(st.empty())
    {
        st.push(ele);
        return;
    }
    
    int topele=st.top();
    st.pop();
    insertatbottom(st,ele);
    
    st.push(topele);
}

// call by reference 
void reverse1(stack<int>&st)
{
    // base case 
    if(st.empty())
    {
        return;
    }
    
    int ele=st.top();
    st.pop();
    reverse1(st);
    insertatbottom(st,ele);
}

int main()
{
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverse1(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
