// Previous Smaller Element 
// Next Smaller Element 

#include<bits/stdc++.h>
using namespace std;

void prevsmaller(vector<int> &arr)
{
    stack<int>st;
    
    for(int i=0;i<arr.size();i++)
    {
        while(!st.empty() and st.top()>=arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            cout<<"-1"<<",";
        }
        else
        {
            cout<<st.top()<<",";
        }
        st.push(arr[i]);
    }
}

void prevgreater(vector<int> &arr)
{
    stack<int>st;
    
    for(int i=0;i<arr.size();i++)
    {
        while(!st.empty() and st.top()<=arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            cout<<"-1"<<",";
        }
        else
        {
            cout<<st.top()<<",";
        }
        st.push(arr[i]);
    }
}


int main()
{ 
    vector<int> arr={4,10,5,18,3,12,7};
    int n=arr.size();
    prevsmaller(arr);
    cout<<endl;
    prevgreater(arr);
    return 0;
}
