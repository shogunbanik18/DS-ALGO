class Solution {
public:
//     using floyd's cycle detection algorithm 
    int checksum(int n)
    {
        int ans=0,tmp;
        while(n)
        {
            tmp=n%10;
            ans+=tmp*tmp;
            n=n/10;
        }
        return ans;
    }
    
    bool isHappy(int n)
    {
        int slow,fast;
        slow=fast=n;
        do
        {
            slow=checksum(slow);
            fast=checksum(fast);
            fast=checksum(fast);
        }while(slow!=fast);
        if(slow==1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
