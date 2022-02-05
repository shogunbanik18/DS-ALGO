#include<bits/stdc++.h>
using namespace std;

// Reverse a string without mdifying special character 
int main()
{
    string s;
    cin>>s;
    
    int n=s.size();
    int i=0;
    int j=n-1;
    string res="";
    while(i<=j)
    {
        if(!isalpha(s[i]))
        {
            i++;
        }
        else if(!isalpha(s[j]))
        {
            j--;
        }
        else
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    cout<<s<<endl;
}
