class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b)
    {
        // int ans=0;
        // int n=(a^b);
        // while(n>0)
        // {
        //     if(n&1)
        //     {
        //         ans++;;
        //     }
        //     n=n>>1;
        // }
        // return ans;
        // // Your logic here
        
        // alter method 
        int count=0;
        while(max(a,b)>0)
        {
            if((a&1)!=(b&1))
            {
                count++;
            }
            a=a>>1;
            b=b>>1;
        }
        return count;
        
    }
};
