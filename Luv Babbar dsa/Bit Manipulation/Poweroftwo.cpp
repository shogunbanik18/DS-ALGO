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

// leetcode 

class Solution {
public:
    // using loop
     bool isPowerOfTwo(int n)
     {
         if(n>0)
         {
             while(n%2==0)
             {
                 n=n/2; 
             }
             if(n==1)
             {
                 return true;
             }
         }
          return false;
        }
    
    // using bitmasking 
//     tc:O(lon n)
    bool isPowerOfTwo(int n) 
    {
        // base case 
        if(n==0 or n<0)
        {
            return false;
        }
        
        if((n&(n-1))==0)
        {
            return true;
        }
        else
        {
            return false;   
        }
    }
};
