// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string s1,s2;
//     cin>>s1>>s2;
    
//     // s1=to_lower(s1.begin(),s1.end());
//     // s2=to_lower(s2.begin(),s2.end());
    
//     transform(s1.begin(), s1.end(), s1.begin(),::toupper);
//     transform(s2.begin(), s2.end(), s2.begin(),::toupper);
    
//     int sum1=0,sum2=0;
//     for(int i=0;i<s1.length();i++)
//     {
//         sum1+=s1[i]-'0';
//     }
//     for(int i=0;i<s2.length();i++)
//     {
//         sum2+=s2[i]-'0';
//     }
//     // cout<<sum1<<" "<<sum2<<endl;
//     if(sum1==sum2)
//     {
//         cout<<0<<endl;
//     }
//     else if(sum1>sum2)
//     {
//         cout<<1<<endl;
//     }
//     else
//     {
//         cout<<-1<<endl;
//     }
// }


#include<bits/stdc++.h>
using namespace std;

int solve(string a,string b)
{
    int n=a.length();
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        
        if(tolower(a[i])>tolower(b[i]))
        {
            return 1;
        }
        else if(tolower(a[i])<tolower(b[i]))
        {
            return -1;
        }
        else
        {
            cnt++;
        }
    }
    if(cnt== a.length())
    {
        return 0;
    }
}

int main()
{
    string a,b;
    cin>>a>>b;
    cout<<solve(a,b)<<endl;
    return 0;
}
