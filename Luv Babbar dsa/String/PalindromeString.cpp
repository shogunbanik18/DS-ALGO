class Solution{
public:	
	
	int isPalindrome(string S)
	{
	    int i=0;
	    int j=S.length()-1;
	    while(i<=j)
	    {
	        if(S[i]!=S[j])
	        {
	            return 0;
	            break;
	        }
	        else
	        {
	            i++;
	            j--;
	        }
	    }
	    return 1;
	    // Your code goes here
	}

};



// ALTER 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string string1;
    int i, length;
    int flag = 0;

    cout << "Enter a string: ";
    cin >> string1;

    length = string1.length();

    for (i = 0; i < length; i++)
    {
        if (string1[i] != string1[length - i - 1])
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        cout << string1 << " is not a palindrome" << endl;
    }
    else
    {
        cout << string1 << " is a palindrome" << endl;
    }
    return 0;
}



// Soltuion 
#include<bits/stdc++.h>
using namespace std;

// palindrome string 
// Recursive way 
bool ispalindrome_recursive(string s,int l,int r)
{
    // base case 
    if(l>=r)
    {
        return true;
    }
    
    else if(s[l]!=s[r])
    {
        return false;
    }
    
    return ispalindrome_recursive(s,l+1,r-1);
}

// iterative way 
// bool ispalindrome(string s)
// {
//     int n=s.size();
//     int l=0;
//     int r=n-1;
//     while(l<=r)
//     {
//         if(s[l]!=s[r])
//         {
//             return false;
//         }
//         l++;
//         r--;
//     }
//     return true;
// }


int main()
{
    string s;
    cin>>s;
    int r=s.size()-1;
    if(ispalindrome_recursive(s,0,r))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

    return 0;
}
