// Previous Smaller Element 
// Next Smaller Element 

#include<bits/stdc++.h>
using namespace std;
 
void nextsmaller(vector<int> &arr)
{
    stack<int>st;
    vector<int>v;
    int n=arr.size();
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() and st.top()>=arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            v.push_back(-1);
        }
        else
        {
            v.push_back(st.top());
        }
        st.push(arr[i]);
    }
    reverse(v.begin(),v.end());
    for(auto x:v)
    {
        cout<<x<<",";
    }
}


void nextgreater(vector<int>arr)
{
    stack<int>st;
    int n=arr.size();
    vector<int>v;
    
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() and st.top()<=arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            v.push_back(-1);
        }
        else
        {
            v.push_back(st.top());
        }
        st.push(arr[i]);
    }
    reverse(v.begin(),v.end());
    for(auto x:v)
    {
        cout<<x<<",";
    }
}

int main()
{ 
    vector<int> arr={3,10,5,1,15,10,7,6};
    // 1,5,1,-1,10,7,6,-1, ans 
    nextsmaller(arr);
    cout<<endl;
    nextgreater(arr);
    return 0;
}
