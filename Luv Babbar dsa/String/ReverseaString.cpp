class Solution {
public:
    // tc:O(N/2)
    void reverseString(vector<char>& s) {
        int start=0;
        int end=s.size()-1;
        while(start<end)
        {
            swap(s[start],s[end]);
            start++;
            end--;
        }
        
        // tc:O(N)
        // SC: O(N)
          // stack<char>st;
//         for(int i=0;i<s.size();i++)
//         {
//             st.push(s[i]);
//         }
        
//         vector<int>v;
//         while(!st.empty())
//         {
//             v.push_back(st.top());
//             st.pop();
//         }
        
// using stl library 
// reverse(s.begin(),s.end());   
    }
};


// using recursion 
#include<bits/stdc++.h>
using namespace std;

void reverse1(string s)
{
    if(s.length()==0)
    {
        return;
    }
    
    string ros=s.substr(1);
    reverse1(ros);
    cout<<s[0];
}

int main()
{
    reverse1("binod");
    return 0;
}
