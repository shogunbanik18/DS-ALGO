// check for power of two 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if ((n & (n - 1)) == 0)

    {
        cout << "Power of 2" << endl;
    }
    else
    {
        cout << "Not power of 2" << endl;
    }

    return 0;
}

// class Solution{
//     public:
//     // Function to check if given number n is a power of two.
//     bool isPowerofTwo(long long n)
//     {
//         if(n<=0)
//         {
//             return false;
//         }
//     //   return (!(n&(n-1)));
//         if((n&(n-1))==0)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//         // Your code here    
        
//     }
};
