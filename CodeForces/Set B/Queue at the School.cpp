#include<bits/stdc++.h>
using namespace std;

// void ans(int n,int t,string s)
// {
//         string res="";
//         queue<char>q;
//         for(int i=0;i<n;i++)
//         {
//             if(s[i]=='B')
//             {
//                 q.push('B');
//             }
//             else if(s[i]=='G')
//             {
//                 res+=s[i];
//                 if(!q.empty())
//                 {
//                     char n=q.front();
//                     res+=n;
//                     q.pop();
//                 }
//             }
//         }
//         cout<<res<<endl;
// }

// int main()
// {
//     int n,t;
//     string s;
//     cin>>n>>t;
//     cin>>s;
//     ans(n,t,s);
//     return0;
// }

int main()
{
    int n,t;
    cin>>n>>t;
    string s;
    cin>>s;
    while(t--)
    {
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='B' and s[i+1]=='G')
            {
                swap(s[i],s[i+1]);
                i++;
            }
        }
    }
    cout<<s<<endl;
    return 0;
}
