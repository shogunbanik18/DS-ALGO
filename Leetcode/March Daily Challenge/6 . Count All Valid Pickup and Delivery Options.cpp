class Solution {
public:
    // using maths permutation and Recursion Combinatorics
//     tc :o(n) +o(n)
//     sc:o(1)
    int countOrders(int n) 
    {
        long res=1,mod=1000000007;
        for(int i=1;i<=n;i++)
        {
            res=res*i;
            res=res%mod;
            res=res*(2*i-1);
            res=res%mod;
        }
        return res%mod;
    }
    
    
//     Overflow 
//     int fact(int n)
//     {
//         if(n==0 or n==1)
//         {
//             return 1;
//         }
//         return n*fact(n-1);
//     }
    
//     int countOrders(int n) 
//     {
//         // int mod =1000000007;
//         // int pickup=fact(n);
//         // int delivery=1;
//         // for(int i=1;i<=2*n-1;i+=2)
//         // {
//         //     delivery =delivery*i;
//         // }
//         // // cout<<pickup<<" " << delivery<<endl;
//         // int count=(pickup*delivery);
//         // return count%mod;
        
//         long res=1,mod=1000000007;
//         for(int i=1;i<=n;i++)
//         {
//             res=res*i;
//             res=res%mod;
//             res=res*(2*i-1);
//             res=res%mod;
//         }
//         return res%mod;
//     }
};



class Solution {
public:
    // using maths permutation and Recursion Combinatorics
    // int countOrders(int n) 
    // {   
    //     long res=1,mod=1000000007;
    //     for(int i=1;i<=n;i++)
    //     {
    //         res=res*i;
    //         res=res%mod;
    //         res=res*(2*i-1);
    //         res=res%mod;
    //     }
    //     return res%mod;
    // }
    
    // using 1d dp 
    int countOrders(int n) 
    {   
        long dp[501];
        int mod = 1000000007;
        dp[1]=1L;
        dp[2]=6L;
        for(int i=3;i<=n;i++)
        {
            int index= 2*i-1;
            int permutation = index* (index+1)/2;
            dp[i]=(dp[i-1]*(permutation))%mod;
        }
        return (int)dp[n];
    }
