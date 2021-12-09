
#include<bits/stdc++.h>
using namespace std;

void caesarcipher(string s,int n,int k)
{
    for(char c:s)
    {
        if(c==' ')
        {
            cout<<c;
        }
        
        if(isalpha(c)==0)
        {
            cout<<c;
        }
        else
        {
            unsigned char en =c+k;
            if(isupper(c) and en>90)
            {
                en=en-26;
            }
            else if(islower(c) and en>122)
            {
                en=en-26;
            }
            // cout<<(int)en<<""<<en;
            cout<<en<<"";
        }
    }
}


// Alter //

string caesarcipher(string s,int k)
{
    string res="";
    for(int i=0;i<s.length();i++)
    {
        if(isupper(s[i]))
        {
            res=res +char(int (s[i]+k-65)%26+65) ; 
        }
        else
        {
            res=res +char(int (s[i]+k-97)%26+97);
        }
    }
    return res;
}


int main()
{
    // int n;
    // cout<<"Enter the length of the string : "<<endl;
    // cin>>n;
    
    int k,n;
    cin>>n;
    // cout<<"Enter the key :"<<endl;
    string s;
    cin>>s;
    cin>> k;
    k=k%26;
    // cout<<"Enter the string : "<<endl;
    // int n=s.size();
    
    
    caesarcipher(s,n,k);
    return 0;
}
